
// Contains the logic of the network and its modules.

#include <omnetpp.h>
#include <string>
#include <iostream>
#include "custom_msg_m.h"

using namespace omnetpp;  // Use all the omnetpp libraries


class My_Node: public cSimpleModule {

    protected:

        void initialize() override;  // Called at beginning of simulation.
        //void handleMessage(cMessage *msg) override;  // Called whenever a message arrives at a My_Node.
        void handleMessage(cMessage *msg) override;

};

Define_Module(My_Node);  // Register the class with OMNET++


// We want node 2 to start the ping.
// We don't want node 1 to start anything.
void My_Node::initialize() {

    if (strcmp("my_Node1", getName()) == 0) {
        //cMessage *msg = new Custom_msg("Hello Neighbor!");


        cMessage *msg = new Custom_msg();

        int count = 0;
        std::string s_msg = "Hello, neighbro! ";
        std::string s_name = s_msg + std::to_string(count);

        static_cast<Custom_msg *>(msg) -> setCount(count);
        static_cast<Custom_msg *>(msg) -> setMsg(s_msg.c_str());
        static_cast<Custom_msg *>(msg) -> setName(s_name.c_str());
        //static_cast<Custom_msg *>(msg) -> setMsg(s_msg.c_str());  // Must use a type cast to get the compiler to accept the statement.

        send(msg, "output_gate");
    }
}

void My_Node::handleMessage(cMessage *msg) {
    int count = static_cast<Custom_msg *>(msg) -> getCount();
    std::string s_msg = static_cast<Custom_msg *>(msg) -> getMsg();
    std::string s_name = s_msg + std::to_string(++count);

    static_cast<Custom_msg *>(msg) -> setCount(count);
    static_cast<Custom_msg *>(msg) -> setMsg(s_msg.c_str());
    static_cast<Custom_msg *>(msg) -> setName(s_name.c_str());

    send(msg, "output_gate");
}

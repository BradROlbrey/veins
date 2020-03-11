package omnetpp;

// Describes the network setup, the configuration of each module in it, and the connections betweens the modules.

// Defines two nodes, which are connected to each other bidriectionally.

network Hello_neighbor
{
    types:
        simple My_Node
        {
            gates:
                input input_gate;
                output output_gate;
        }

    submodules:
        my_Node1: My_Node {
            @display("p=73,70");
        }
        my_Node2: My_Node {
            @display("p=235,70");
        }
    
    connections:
        my_Node1.output_gate --> my_Node2.input_gate;
        my_Node2.output_gate --> my_Node1.input_gate;
}

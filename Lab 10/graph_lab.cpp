#include <iostream>
#include<list>

#include <vector>

using namespace std;



struct Node{
    // A node will have 2 entities
    //1. data type int called label
    //2. a int type list called neighbours
    int label;
    list<int> neighbours;

};

struct Graph{
    //graph will have an array of type "node" with length specified by n
    int n = 8; // The lab sheet contained a graph with 8 nodes
    Node * nodes = new Node[n];

    void intializenodes(){
        //iterate through the nodes and assign labels
        for(int i = 0; i < n; i++){
            nodes[i].label = i;
        }
    }

    void addedge(int u, int v){
        //select node u and push v into u's neighbour
        // Since our array of Nodes is 0-indexed, (u-1)th index 
        // represents Node with label `u`
        (nodes[u - 1]).neighbours.push_back(v);

        //select node v and push u into v's neighbour
        (nodes[v - 1]).neighbours.push_back(u);
    }
    
    void print(){
        //lets iterate through each node and print its neighbours
        for (int i = 0; i < n; i++) {

            cout << nodes[i].label;

            cout << " ---> [ ";

            // Iterate through the list of neighbours
            for (int val : nodes[i].neighbours) {

                cout << val << ((val == nodes[i].neighbours.back() ?  " ]\n" : ", "));

            }
        }
    }
};


int main() {
    Graph * g = new Graph;
    g->intializenodes();
    //add edges for the graphs here.

    // Adding edges of vertex 1
    g->addedge(1, 2);
    g->addedge(1, 3);
    g->addedge(1, 4);
    g->addedge(1, 5);

    // Vertex 2
    // Edge with 1 already added
    g->addedge(2, 3);
    g->addedge(2, 6);

    // Vertex 3
    // Edge with 1 already added
    // Edge with 2 already added

    // Vertex 4
    // Edge with 1 already added
    g->addedge(4, 6);
    g->addedge(4, 7);
    g->addedge(4, 8);

    // Vertex 5
    // Edge with 1 already added
    g->addedge(5, 6);
    g->addedge(5, 7);
    g->addedge(5, 8);

    // Vertex 6
    // Edge with 2 already added
    // Edge with 4 already added
    // Edge with 5 already added

    // Vertex 7
    // Edge with 4 already added
    // Edge with 5 already added

    // Vertex 8
    // Edge with 4 already added
    // Edge with 5 already added
    
    //print the graph adjaceny list
    g->print();
}

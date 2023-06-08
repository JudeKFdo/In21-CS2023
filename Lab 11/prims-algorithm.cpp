#include <iostream>
#include <vector>
#include <map>

#define INFINITY INT_MAX
#define VERTICES 6

using namespace std;

// To represent a neighbour in the adjacecny list
struct Neighbour {
    int vertex;
    int weight;

    Neighbour(int vertex, int val) {
        this->vertex = vertex;
        this->weight = val;
    }
};

/**
 * Return the vertex with the minimum weight
*/
int return_min(bool visited[], int min_weight[]) {
    int min = INFINITY;
    int min_vertex = 0;

    for (int i = 0; i < VERTICES; i++) {

        if (!visited[i] && min_weight[i] < min) {
            min = min_weight[i];
            min_vertex = i; 
        }
    }

    return min_vertex;
}

/**
 * Actual implementation of Prim's algorithm
 * Prints out the predecessor sub-graph of the MST and their
 * associated weight. From this we can get the MST.
*/
void prims(vector<vector<Neighbour>> adj, int source) {

    // To keep track of the minimum weight
    int min_weights[VERTICES];
    fill(min_weights, min_weights + VERTICES, INFINITY);
    min_weights[source] = 0;

    // To keep track of the vertices we've already visited
    bool visited[VERTICES] = { false };

    // Keep track of the predecessors of each vertex
    int predecessors[VERTICES] = { -1 };

    // Implementing Prim's algorithm
    for (int i = 0; i < VERTICES - 1; i++) {

        int min_vertex = return_min(visited, min_weights);
        visited[min_vertex] = true;

        for (Neighbour &neighbour : adj[min_vertex]) {

            if (!visited[neighbour.vertex] && neighbour.weight < min_weights[neighbour.vertex]) {
                // If the vertex is unvisited and the current edge has lower
                // weight than the minimum weight associated with that vertex,
                // update the minimum weight and predecessor of that vertex
                min_weights[neighbour.vertex] = neighbour.weight;
                predecessors[neighbour.vertex] = min_vertex;
            }
        }

    }

    // Print out
    cout << "\n Edge\t:\t\b\bWeight\n";
    for (int vertex = 0; vertex < VERTICES; vertex++) {
        if (vertex != source) {
            cout << vertex << " - " << predecessors[vertex] << "\t:\t" << min_weights[vertex] << "\n";
        }
    }
    cout << endl;

    // Cleanup
    for (auto& row : adj) {
        row.clear();
    }

}

int main() {

    // Represent graph as adjacency list. Neighbour() has two arguements
    // as Neighbour(int vertex, int weight)
    vector<vector<Neighbour>> adj = {
        {Neighbour(1, 3), Neighbour(5, 1)},
        {Neighbour(0, 3), Neighbour(2, 2), Neighbour(3, 1), Neighbour(4, 10)},
        {Neighbour(1, 2), Neighbour(3, 3), Neighbour(5, 5)},
        {Neighbour(1, 1), Neighbour(2, 3), Neighbour(4, 10)},
        {Neighbour(1, 10), Neighbour(3, 5), Neighbour(5, 4)},
        {Neighbour(0, 1), Neighbour(2, 5), Neighbour(4, 4)}
    };

    int source = 0;
    prims(adj, source);

    return 0;
}
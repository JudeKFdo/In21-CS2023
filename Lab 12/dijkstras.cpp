#include <iostream>
#include <vector>

#define NODES 6
#define INFINITY INT_MAX

using namespace std;

/**
 * Used to find the unvisited vertex with the minimum shortest distance
*/
int min_distance(int distances[], bool visited[]) {
    int min_value = INFINITY;
    int min_index;

    for (int i = 0; i < NODES; i++) {
        if (!visited[i] && distances[i] <= min_value) {
            min_value = distances[i];
            min_index = i;
        }
    }

    return min_index;
}

/**
 * Relaxing a given edge. `in_node` is the node that the edge goes into, while
 * `out_node` is the node that the edge goes out of. Then for an edge u-->v
 * 'u' would be the `out_node` and 'v' would be the `in_node`.
*/
void relax(int adj[NODES][NODES], int distances[], int out_node, int in_node) {

    if (adj[out_node][in_node] == 0) {
        // Means there is either no edge between the nodes.
        return;
    }
    
    // New upper-bound for shortest distance
    int cost = distances[out_node] + adj[out_node][in_node];

    if (distances[in_node] > cost) {
        // Means new upper-bound is lower than the previous

        // Lower the upper-bound on the shortest-path cost to new value
        distances[in_node] = cost;

    }
}

/**
 * Print the shortest cost to each vertex
*/
void print_solution(int distances[], int start) {

    cout << "\n\nFor start vertex: " << start << "\n";
    cout << "Vertex" << "\t\t\t" << "Distance" << "\n";

    for (int i = 0; i < NODES; i++) {
        cout << i << "\t\t\t" << distances[i] << "\n";
    }

    cout << "\n" << endl;
    return;

}

/**
 * Find the average time from `start` node to each other node
*/
void average_time(int start, int distances[]) {

    int sum = 0;
    for (int i = 0; i < NODES; i++) {
        sum += distances[i];
    }

    cout << start << "\t\t" << (sum * 1.0) / (NODES - 1) << "\n";

}



/**
 * Implementing Dijkstra's shortest-path algorithm
*/
void dijkstra(int adj[NODES][NODES], int n, int start) {

    // To keep track of the vertices we've visited
    bool visited[n] = { false };

    // To store the (upper-bound) for the shortest
    // distance from source to each node
    int distances[n];

    // Initialize all distances to `INFINITY`
    fill(&distances[0], (&distances[NODES - 1] + 1), INFINITY); 

    // Initialize distance to start vertex as 0
    distances[start] = 0;


    for (int i = 0; i < NODES; i++) {

        int min = min_distance(distances, visited);

        // Mark node with index `min` as visited
        visited[min] = true;

        // Relax the edges going out of vertex with index `min`
        for (int j = 0; j < NODES; j++) {

            if (!visited[j] && adj[min][j] != 0) {

                relax(adj, distances, min, j);

            }
        }
    }

    // To print the solution for each node, uncomment the following:
    //print_solution(distances, start);

    // Prints the average time taken to reach other cities from `start` vertex
    average_time(start, distances);

}


int main() {

    // Adjacency matrix
    int adj[NODES][NODES] = {
        {0, 10, 0, 0, 15, 5},
        {10, 0, 10, 30, 0, 0},
        {0, 10, 0, 12, 5, 0},
        {0, 30, 12, 0, 0, 20},
        {15, 0, 5, 0, 0, 0},
        {5, 0, 0, 20, 0, 0}
    };

    // Since we're printing average times. If printing solution for each node
    // comment out the following:
    cout << "\n\nVertex" << "\t\t" << "Average Time" << "\n";

    // Running Dijkstra's algorithm for each vertex and printing average for each
    for (int source = 0; source < NODES; source++) {
        dijkstra(adj, NODES, source);
    }
    cout << "\n\n";

    // To print the solution for individual vertices, comment out the above
    // and uncomment the following:
    /* int source = 0;
    dijkstra(adj, NODES, source); */

    return 0;
}


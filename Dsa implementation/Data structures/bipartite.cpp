#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Function to check if the graph is bipartite using BFS
bool isBipartite(vector<vector<int>>& graph, int n) {
    vector<int> colors(n, -1); // Initialize colors of all vertices as -1
    queue<int> q;

    for (int i = 0; i < n; ++i) {
        if (colors[i] == -1) { // If vertex i is not colored
            colors[i] = 0; // Color vertex i with 0 (or any arbitrary color)
            q.push(i);

            while (!q.empty()) {
                int node = q.front();
                q.pop();

                for (int neighbor : graph[node]) {
                    if (colors[neighbor] == -1) { // If neighbor is not colored
                        colors[neighbor] = 1 - colors[node]; // Color neighbor with the opposite color
                        q.push(neighbor);
                    } else if (colors[neighbor] == colors[node]) { // If neighbor has the same color as node
                        return false; // The graph is not bipartite
                    }
                }
            }
        }
    }

    return true; // If no conflicts are found, the graph is bipartite
}

int main() {
    int n = 4; // Number of nodes in the graph

    // Example of an undirected graph represented using an adjacency list
    vector<vector<int>> graph = {
        {1, 3},     // Node 0 is connected to nodes 1 and 3
        {0, 2},     // Node 1 is connected to nodes 0 and 2
        {1},        // Node 2 is connected to node 1
        {0, 4},     // Node 3 is connected to nodes 0 and 4
        {3}         // Node 4 is connected to node 3
    };

    // Check if the graph is bipartite
    if (isBipartite(graph, n)) {
        cout << "The graph is bipartite." << endl;
    } else {
        cout << "The graph is not bipartite." << endl;
    }

    return 0;
}

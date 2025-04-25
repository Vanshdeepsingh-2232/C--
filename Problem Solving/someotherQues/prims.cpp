#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <limits>

using namespace std;

#define INF numeric_limits<int>::max()

// Edge structure to represent a weighted edge
struct Edge {
    int to;
    int weight;
    Edge(int _to, int _weight) : to(_to), weight(_weight) {}
};

// Function to perform Prim's algorithm
vector<vector<Edge>> prim(const vector<vector<Edge>>& graph) {
    int n = graph.size();
    vector<bool> visited(n, false);
    vector<vector<Edge>> mst(n); // Minimum Spanning Tree
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // Min-heap

    // Start Prim's algorithm from vertex 0
    visited[0] = true;
    for (const Edge& e : graph[0]) {
        pq.push({e.weight, e.to});
    }

    while (!pq.empty()) {
        int weight = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (visited[u]) {
            continue;
        }

        visited[u] = true;

        // Add the edge to the minimum spanning tree
        if (u != 0) { // Exclude the root node
            int parent = -1; // Parent node of u in the minimum spanning tree
            for (const Edge& e : graph[u]) {
                if (visited[e.to]) {
                    parent = e.to;
                    break;
                }
            }
            if (parent != -1) {
                mst[parent].push_back({u, weight});
                mst[u].push_back({parent, weight});
            }
        }

        // Explore neighbors of u
        for (const Edge& e : graph[u]) {
            if (!visited[e.to]) {
                pq.push({e.weight, e.to});
            }
        }
    }

    return mst;
}

int main() {
    int n = 6; // Number of nodes

    // Example of a weighted undirected graph represented using an adjacency list
    vector<vector<Edge>> graph = {
        {{1, 6}, {3, 1}},  // Node 0 is connected to nodes 1 (weight 6) and 3 (weight 1)
        {{0, 6}, {2, 5}, {3, 2}, {4, 5}}, // Node 1 is connected to nodes 0 (weight 6), 2 (weight 5), 3 (weight 2), and 4 (weight 5)
        {{1, 5}, {4, 6}}, // Node 2 is connected to nodes 1 (weight 5) and 4 (weight 6)
        {{0, 1}, {1, 2}, {4, 1}, {5, 3}}, // Node 3 is connected to nodes 0 (weight 1), 1 (weight 2), 4 (weight 1), and 5 (weight 3)
        {{1, 5}, {2, 6}, {3, 1}, {5, 2}}, // Node 4 is connected to nodes 1 (weight 5), 2 (weight 6), 3 (weight 1), and 5 (weight 2)
        {{3, 3}, {4, 2}} // Node 5 is connected to nodes 3 (weight 3) and 4 (weight 2)
    };

    vector<vector<Edge>> mst = prim(graph);

    // Output the minimum spanning tree
    cout << "Minimum Spanning Tree:\n";
    for (int i = 0; i < n; ++i) {
        for (const Edge& e : mst[i]) {
            cout << "Edge: " << i << " - " << e.to << " Weight: " << e.weight << endl;
        }
    }

    return 0;
}

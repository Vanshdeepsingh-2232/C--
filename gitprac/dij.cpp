#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

#define INF numeric_limits<int>::max()

// Edge structure to represent a weighted edge
struct Edge {
    int to;
    int weight;
    Edge(int _to, int _weight) : to(_to), weight(_weight) {}
};

// Function to perform Dijkstra's algorithm
vector<int> dijkstra(const vector<vector<Edge>>& graph, int start) {
    int n = graph.size();
    vector<int> dist(n, INF); // Initialize distances to INF
    vector<bool> visited(n, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // Min-heap

    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if (visited[u])
            continue;

        visited[u] = true;

        for (const Edge& e : graph[u]) {
            int v = e.to;
            int weight = e.weight;
            if (dist[u] != INF && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }

    return dist;
}

int main() {
    int n = 5; // Number of nodes
    int start = 0; // Starting node

    // Example of a weighted directed graph represented using an adjacency list
    vector<vector<Edge>> graph = {
        {{1, 10}, {2, 5}}, // Node 0 is connected to nodes 1 (weight 10) and 2 (weight 5)
        {{3, 1}},          // Node 1 is connected to node 3 (weight 1)
        {{1, 3}, {3, 9}},  // Node 2 is connected to nodes 1 (weight 3) and 3 (weight 9)
        {{4, 2}},          // Node 3 is connected to node 4 (weight 2)
        {}                 // Node 4 has no outgoing edges
    };

    vector<int> distances = dijkstra(graph, start);

    cout << "Shortest distances from node " << start << ":\n";
    for (int i = 0; i < n; ++i) {
        if (distances[i] == INF)
            cout << "Node " << i << ": unreachable\n";
        else
            cout << "Node " << i << ": " << distances[i] << "\n";
    }

    return 0;
}

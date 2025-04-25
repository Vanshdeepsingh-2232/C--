#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

// Function to find connected components of an undirected graph using BFS
vector<unordered_set<int>> findConnectedComponents(vector<vector<int>>& graph, int n) {
    vector<bool> visited(n, false);
    vector<unordered_set<int>> components;
    
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            unordered_set<int> component;
            queue<int> q;
            q.push(i);
            visited[i] = true;

            while (!q.empty()) {
                int node = q.front();
                q.pop();
                component.insert(node);

                for (int neighbor : graph[node]) {
                    if (!visited[neighbor]) {
                        q.push(neighbor);
                        visited[neighbor] = true;
                    }
                }
            }
            components.push_back(component);
        }
    }
    return components;
}

int main() {
    int n = 6; // Number of nodes in the graph

    // Example of an undirected graph represented using an adjacency list
    vector<vector<int>> graph = {
        {1, 3},     // Node 0 is connected to nodes 1 and 3
        {0, 2},     // Node 1 is connected to nodes 0 and 2
        {1},        // Node 2 is connected to node 1
        {0, 4},     // Node 3 is connected to nodes 0 and 4
        {3, 5},     // Node 4 is connected to nodes 3 and 5
        {4}         // Node 5 is connected to node 4
    };

    // Find connected components
    vector<unordered_set<int>> components = findConnectedComponents(graph, n);

    // Output the connected components
    cout << "Connected components of the graph:" << endl;
    for (size_t i = 0; i < components.size(); ++i) {
        cout << "Component " << i + 1 << ": ";
        for (int node : components[i]) {
            cout << node << " ";
        }
        cout << endl;
    }

    return 0;
}

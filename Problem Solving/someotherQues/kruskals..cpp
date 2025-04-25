#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Edge structure to represent a weighted edge
struct Edge {
    int from;
    int to;
    int weight;
    Edge(int _from, int _to, int _weight) : from(_from), to(_to), weight(_weight) {}
};

// Disjoint Set Union (DSU) data structure for implementing Kruskal's algorithm
class DSU {
private:
    vector<int> parent;
    vector<int> rank;

public:
    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX == rootY) {
            return;
        }
        if (rank[rootX] < rank[rootY]) {
            parent[rootX] = rootY;
        } else if (rank[rootX] > rank[rootY]) {
            parent[rootY] = rootX;
        } else {
            parent[rootY] = rootX;
            rank[rootX]++;
        }
    }
};

// Function to perform Kruskal's algorithm
vector<Edge> kruskal(const vector<Edge>& edges, int numNodes) {
    // Sort edges in non-decreasing order of weight
    vector<Edge> sortedEdges = edges;
    sort(sortedEdges.begin(), sortedEdges.end(), [](const Edge& a, const Edge& b) {
        return a.weight < b.weight;
    });

    DSU dsu(numNodes);
    vector<Edge> mst;

    // Add edges to the minimum spanning tree until all nodes are connected
    for (const Edge& edge : sortedEdges) {
        if (dsu.find(edge.from) != dsu.find(edge.to)) {
            mst.push_back(edge);
            dsu.unite(edge.from, edge.to);
        }
    }

    return mst;
}

int main() {
    int n = 6; // Number of nodes

    // Example of a weighted undirected graph represented using a list of edges
    vector<Edge> edges = {
        {0, 1, 6}, {0, 3, 1}, {1, 2, 5}, {1, 3, 2}, {1, 4, 5}, {2, 4, 6}, {3, 4, 1}, {3, 5, 3}, {4, 5, 2}
    };

    vector<Edge> mst = kruskal(edges, n);

    // Output the minimum spanning tree
    cout << "Minimum Spanning Tree:\n";
    for (const Edge& edge : mst) {
        cout << "Edge: " << edge.from << " - " << edge.to << " Weight: " << edge.weight << endl;
    }

    return 0;
}

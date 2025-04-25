#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <set>
using namespace std;

class Solution
{
private:
    unordered_map<int, vector<pair<int, int>>> adj_list;

    void print_adjacency_list()
    {
        for (const auto &mapEntry : adj_list)
        {
            int vertex = mapEntry.first;
            const vector<pair<int, int>> &neighbors = mapEntry.second;

            cout << "Vertex " << vertex << " connects to: ";
            for (const auto &neighbor : neighbors)
            {
                cout << "(Vertex: " << neighbor.first << ", Weight: " << neighbor.second << ") ";
            }
            cout << endl;
        }
    }
    void create_adjacency_list(vector<vector<int>> &edges)
    {
        int u = 0;
        int v = 1;
        int w = 2;
        for (int i = 0; i < edges.size(); i++)
        {
            pair<int, int> pairs = make_pair(edges[i][v], edges[i][w]);
            adj_list[edges[i][u]].push_back(pairs);
        }
    }

public:
    Solution() {}

    int networkDelayTime(vector<vector<int>> &times, int n, int k)
    {
        create_adjacency_list(times);

        set<pair<int, int>> SET_STRUCT;
        vector<int> Distances(n, INT32_MAX);

        int source = k;
        Distances[source] = -1;
        // while storing the intial pair in set pair.first=distance && pair.second= node V;
        pair<int, int> intial_pair = make_pair(0, source);
        SET_STRUCT.insert(intial_pair);

        while (!SET_STRUCT.empty())
        {
            auto top = *(SET_STRUCT.begin());
            int top_node_W = top.first;
            int top_node_V = top.second;

            SET_STRUCT.erase(top);

            for (auto &Connected_nodes : adj_list[top_node_V])
            {
                int node_V = Connected_nodes.first;
                int node_W = Connected_nodes.second;

                if (top_node_W + node_W < Distances[node_V])
                {
                    Distances[node_V] = top_node_W + node_W;
                    auto record = SET_STRUCT.find(make_pair(Distances[node_V], node_V));

                    if (record != SET_STRUCT.end())
                    {
                        SET_STRUCT.erase(record);
                    }
                    SET_STRUCT.insert(make_pair(top_node_W + node_W, node_V));
                }
            }
        }
        for (int i = 0; i < Distances.size(); i++)
        {
            cout << Distances[i] << "__";
        }
        
        if(Distances[n-1]==INT32_MAX) return -1;
        else return Distances[n-1];

    }
};

int main()
{
    vector<vector<int>> times = {{2, 1, 1}, {2, 3, 1}, {3, 4, 1}};
    int n = 4, k = 2;

    Solution s1;
    cout<<s1.networkDelayTime(times, n + 1, k);

    return 0;
}
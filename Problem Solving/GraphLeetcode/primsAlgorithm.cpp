#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
using namespace std;

class Graph
{
private:
    int number_of_nodes = 0;
    unordered_map<int, vector<pair<int, int>>> adj_list;
    priority_queue<pair<int, int>> priorityQ;

public:
    int cost = 0;
    Graph(int no = 0)
    {
        number_of_nodes = no;
    }

    void create_adjacency_list(vector<vector<int>> &edges)
    {
        int u = 0, v = 1, W = 2;
        for (int i = 0; i < edges.size(); i++)
        {
            pair<int, int> pairs = make_pair(edges[i][v], edges[i][W]);
            adj_list[edges[i][u]].push_back(pairs);
        }
    }
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

    pair<int, int> find_min(vector<int> &k, vector<bool> &mst)
    {
        pair<int, int> min = make_pair(0, INT16_MAX);
        for (int i = 0; i < k.size(); i++)
        {
            if (k[i] < min.second && !mst[i])
            {
                min.first = i;
                min.second = k[i];
            }
        }
        return min;
    }

    void prims(int source)
    {
        vector<int> key(number_of_nodes, INT16_MAX);
        vector<int> parent(number_of_nodes, -1);
        vector<bool> mst(number_of_nodes, false);

        key[source] = 0;
        parent[source] = -1;

        for (int i = 0; i < number_of_nodes; i++)
        {
            pair<int, int> min_u = find_min(key, mst);
            mst[min_u.first] = true;
            for (auto &C_nodes : adj_list[min_u.first])
            {
                int C_node_name = C_nodes.first;
                int C_node_weight = C_nodes.second;

                if (mst[C_node_name] == false && key[C_node_name] > C_node_weight)
                {
                    key[C_node_name] = C_node_weight;
                    parent[C_node_name] = min_u.first;
                }
            }
        }

        int cost = 0;
        for (int i = 0; i < number_of_nodes; i++)
        {
            cout << key[i] << "__";
            cost += key[i];
        }
        cout << endl;
        cout << " TOTAL MST COST " << cost;
        cout << endl;
        for (int i = 0; i < number_of_nodes; i++)
        {
            cout << parent[i] << "__";
        }
        cout << endl;
        for (int i = 0; i < number_of_nodes; i++)
        {
            cout << mst[i] << "__";
        }
    }
};

int main()
{

    vector<vector<int>> input_graph = {{0, 1, 2},
                                       {0, 3, 6},
                                       {1, 0, 2},
                                       {1, 2, 3},
                                       {1, 3, 8},
                                       {1, 4, 5},
                                       {2, 1, 3},
                                       {2, 4, 7},
                                       {3, 0, 6},
                                       {3, 1, 8},
                                       {4, 1, 5},
                                       {4, 2, 7}};

    Graph g1(5);
    g1.create_adjacency_list(input_graph);
    g1.print_adjacency_list();

    g1.prims(0);

    return 0;
}
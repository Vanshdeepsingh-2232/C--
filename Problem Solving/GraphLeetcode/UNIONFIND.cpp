#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <set>
using namespace std;

class UnionFind
{
private:
    int no_of_nodes = 0;
    vector<int> parent;
    vector<int> rank;

public:
    void printSetOfVectors(const set<vector<int>> &edges)
    {
        for (const auto &edge : edges)
        {
            cout << "[";
            for (size_t i = 0; i < edge.size(); ++i)
            {
                cout << edge[i];
                if (i < edge.size() - 1)
                {
                    cout << ", ";
                }
            }
            cout << "]" << endl;
        }
    }
    template <typename T>
    void printVector(const vector<T> &vec)
    {
        cout << "[";
        for (size_t i = 0; i < vec.size(); ++i)
        {
            cout << vec[i];
            if (i < vec.size() - 1)
            {
                cout << ", ";
            }
        }
        cout << "]" << endl;
    }
    UnionFind(int n) : parent(n), rank(n)
    {
        no_of_nodes = n;
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
            rank[i] = 0;
        }
    }

    int find_parent(int node)
    {
        if (parent[node] == node)
        {
            return parent[node];
        }

        return parent[node] = find_parent(parent[node]);
    }

    void Union(int u, int v)
    {
        int parent_u = find_parent(u);
        int parent_v = find_parent(v);

        if (rank[parent_u] == rank[parent_v])
        {
            parent[parent_v] = u;
            rank[parent_u]++;
        }
        else if (rank[parent_u] < rank[parent_v])
        {
            parent[parent_u] = parent_v;
        }
        else if (rank[parent_u] > rank[parent_v])
        {
            parent[parent_v] = parent_u;
        }
    }

    void find_mst_kruskals(vector<vector<int>> &G)
    {

        set<vector<int>> edges;

        for (int i = 0; i < G.size(); i++)
        {
            vector<int> v = {G[i][2], G[i][0], G[i][1]};
            edges.insert(v);
        }

        int w = 0, u = 1, v = 2;
        int min_weight = 0;
        while (!edges.empty())
        {
            auto set_top = *(edges.begin());
            vector<int> Vn = set_top;
            edges.erase(set_top);

            int parent_u = find_parent(Vn[u]);
            int parent_v = find_parent(Vn[v]);

            if (parent_u != parent_v)
            {
                min_weight += Vn[w];
                Union(parent_u, parent_v);
            }
            else
                continue;
        }

        cout << "FINAL ANSWER IS : " << min_weight;
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

    UnionFind u1(5);
    u1.find_mst_kruskals(input_graph);
    return 0;
}
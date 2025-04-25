#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;
class Solution
{
public:
    void createAdjList(int v, vector<pair<int, int>> &edges, vector<vector<int>> &Graph)
    {
        for (auto &i : edges)
        {
            int u = i.first;
            int v = i.second;
            Graph[u].push_back(v);
            Graph[v].push_back(u);
        }
    }

    bool isSafe(int &node, int curr_color, vector<vector<int>> &Graph, vector<int> &colorHash)
    {
        for (auto &i : Graph[node])
        {
            if (curr_color == colorHash[i])
                return false;
        }
        return true;
    }

    bool solve(int node, vector<int> &colorHash, vector<vector<int>> &Graph, int m, int v)
    {

        if (node == v)
        {
            return true;
        }

        for (int i = 1; i <= m; i++)
        {
            if (isSafe(node, i, Graph, colorHash))
            {
                colorHash[node] = i;
                if (solve(node + 1, colorHash, Graph, m, v))
                    return true;
                colorHash[node] = 0;
            }
        }
        return false;
    }
    bool graphColoring(int v, vector<pair<int, int>> &edges, int m)
    {
        vector<vector<int>> Graph(v);
        createAdjList(v, edges, Graph);
        vector<int> colorHash(v, 0);
        int ith_vertex = 0;
        if (solve(ith_vertex, colorHash, Graph, m, v) == true)
            return true;
        return false;
    }
};

int main()
{
    vector<pair<int, int>> eg = {{0, 1}, {1, 2}, {0, 2}};
    Solution s1;
    int v = 3;
    cout << s1.graphColoring(v, eg, 2);
    return 0;
}

// class Graph
// {
// private:
//   int number_of_nodes = 0;
//   unordered_map<int, vector<int>> adj_list;

// public:
//   Graph(int no = 0) { number_of_nodes = no; }

//   void create_adjacency_list(vector<vector<int>> &edges)
//   {
//     int n = edges.size();
//     for (int i = 0; i < edges.size(); i++)
//     {
//       adj_list[edges[i][0]].push_back(edges[i][1]);
//       adj_list[edges[i][1]].push_back(edges[i][0]);
//     }
//   }
//   void print_adj_list()
//   {
//     for (auto it = adj_list.begin(); it != adj_list.end(); ++it)
//     {
//       cout << it->first << "{";
//       for (auto neighbor : it->second)
//       {
//         cout << neighbor << ",";
//       }
//       cout << "}" << endl;
//     }
//   }

// };
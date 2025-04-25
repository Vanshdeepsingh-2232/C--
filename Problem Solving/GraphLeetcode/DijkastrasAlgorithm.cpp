#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <set>
#include <utility>
using namespace std;

// DIJKASTRAS ALGORITHM

class Graph
{

private:
  int number_of_nodes = 0;
  unordered_map<int, vector<pair<int, int>>> adj_list;

public:
  Graph(int no = 0) { number_of_nodes = no; }

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

  void shortest_path(int source)
  {
    set<pair<int, int>> SET_STRUCT;
    vector<int> Distance(number_of_nodes, INT32_MAX);

    Distance[source] = 0;
    pair<int, int> pair = make_pair(0, source);
    SET_STRUCT.insert(pair);

    // auto top=*(SET_STRUCT.begin());
    //  cout<<top.first<<" __ "<<top.second;

    while (!SET_STRUCT.empty())
    {

      auto top = *(SET_STRUCT.begin());
      int top_node_weight = top.first;
      int top_node = top.second;

      SET_STRUCT.erase(top);

      for (auto &C_nodes : adj_list[top_node])
      {

        int connected_node = C_nodes.first;
        int connected_node_weight = C_nodes.second;

        if (top_node_weight + connected_node_weight < Distance[connected_node])
        {
          Distance[connected_node] = top_node_weight + connected_node_weight;
          auto record = SET_STRUCT.find(make_pair(Distance[connected_node], connected_node));

          // find function will also return a pointer which points to element found 
          //and if the element is not found it will point to the SET_STRUCT.end();
          if (record != SET_STRUCT.end())
          {
            SET_STRUCT.erase(record);
          }
          SET_STRUCT.insert(make_pair(top_node_weight + connected_node_weight, connected_node));
        }
      }
    }

    for (int i = 0; i < Distance.size(); i++)
    {
      cout << Distance[i] << "__";
    }
  }
};

int main()
{
  Graph g1(5);
  vector<vector<int>> Graph_input = {{0, 1, 7},
                                     {0, 2, 1},
                                     {0, 3, 2},
                                     {1, 0, 7},
                                     {1, 2, 3},
                                     {1, 3, 5},
                                     {1, 4, 1},
                                     {2, 0, 1},
                                     {2, 1, 3},
                                     {3, 0, 2},
                                     {3, 1, 5},
                                     {3, 4, 7},
                                     {4, 1, 1},
                                     {4, 3, 7}};

  g1.create_adjacency_list(Graph_input);
  g1.print_adjacency_list();
  g1.shortest_path(0);
  return 0;
}
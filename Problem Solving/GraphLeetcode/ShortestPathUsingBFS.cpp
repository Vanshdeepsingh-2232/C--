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
  unordered_map<int, vector<int>> adj_list;
  vector<int> path;

public:
  Graph(int no = 0) { number_of_nodes = no; }

  void create_adjacency_list(vector<vector<int>> &edges)
  {
    int n = edges.size();
    for (int i = 0; i < edges.size(); i++)
    {
      adj_list[edges[i][0]].push_back(edges[i][1]);
      adj_list[edges[i][1]].push_back(edges[i][0]);
    }
  }
  void print_adj_list()
  {
    for (auto it = adj_list.begin(); it != adj_list.end(); ++it)
    {
      cout << it->first << "{";
      for (auto neighbor : it->second)
      {
        cout << neighbor << ",";
      }
      cout << "}" << endl;
    }
  }
  void print_path()
  {
    for (int i = 0; i < path.size(); i++)
    {
      cout << "->" << path[i];
    }
  }
  void find_path(int n, int source, vector<int> &parent_record)
  {
    if (n == source)
    {
      path.push_back(n);
      return;
    }
    path.push_back(n);
    n = parent_record[n];
    find_path(n, source, parent_record);
  }
  void bfs(int source, int destination)
  {
    queue<int> q;
    vector<bool> traversed(number_of_nodes, false);
    vector<int> parent_record(number_of_nodes + 1, 0);
    traversed[source] = true;
    q.push(source);
    while (!q.empty())
    {
      int processed = q.front();
      q.pop();
      vector<int> connected_nodes = adj_list[processed];
      for (int i = 0; i < connected_nodes.size(); i++)
      {
        if (!traversed[connected_nodes[i]])
        {
          q.push(connected_nodes[i]);
          traversed[connected_nodes[i]] = true;
          if (parent_record[connected_nodes[i]] == 0)
            parent_record[connected_nodes[i]] = processed;
        }
      }
    }
    // NOW LETS FIND SHORTEST PATH FROM PARENTS RECORD

    find_path(destination, source, parent_record);
  }
};

int main()
{
  Graph g1(7);
  vector<vector<int>> Graph_input = {{1, 2}, {1, 3}, {1, 4}, {2, 5}, {3, 7}, {4, 6}, {5, 7}, {6, 7}};
  g1.create_adjacency_list(Graph_input);
  g1.print_adj_list();
  g1.bfs(1, 7);
  g1.print_path();
  return 0;
}
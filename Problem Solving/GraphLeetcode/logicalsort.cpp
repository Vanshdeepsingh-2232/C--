#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
#include <stack>
#include<set>
using namespace std;

class Graph {
private:
  map<int, vector<int>> adj_list;
  stack<int> s;
  vector<int> answer;
public:
  void print_list() {
    for (const auto &pair : adj_list) {
      int vertex = pair.first;
      const vector<int> &neighbors = pair.second;

      cout << "Vertex " << vertex << " is connected to: ";
      for (int neighbor : neighbors) {
        cout << neighbor << " ";
      }
      cout << endl;
    }
    cout << "SIZE OF THE LIST " << adj_list.size() << "-" << endl;
  }
  
  void create_adj_list(vector<vector<int>> &G) {
    for (auto &edge : G) {
      int u = edge[0];
      int v = edge[1];
      adj_list[u].push_back(v);
    }
  }

  int validsource() {
    vector<int> indegrees(adj_list.size() + 1, 0);
    for (auto &pair : adj_list) {
      vector<int> &neighbours = pair.second;
      for (int node : neighbours) {
        indegrees[node]++;
      }
    }
    int Valid_source_node = 1;
    for (int i = 1; i <= adj_list.size(); i++) {
      if (indegrees[i] == 0) {
        Valid_source_node = i;
        break;
      }
    }
    return Valid_source_node;
  }

  void topological_sort(int node){
     
    vector<bool> visited(adj_list.size()+1,false);
    visited[node]=true;
    vector<int> neighbours=adj_list[node];
    for(int i=0;i<neighbours.size();i++){
      if(!visited[neighbours[i]]){
        topological_sort(neighbours[i]);
      }
    }
    s.push(node);
    
  }


void sortorder() {
  while (!s.empty()) {
    answer.push_back(s.top());
    s.pop();
  }
  for (int i = 0; i < answer.size(); i++)
  {
    cout<<answer[i];
  }
}

  


  ~Graph() {}


};

int main() {
  Graph g1;
  vector<vector<int>> G = {{1, 2}, {1, 3}, {2, 4}, {3, 4},
                           {4, 5}, {4, 6}, {5, 6},{6,0}};
  g1.create_adj_list(G);
  // g1.print_list();
  int node=g1.validsource();
  g1.topological_sort(node);
  g1.sortorder();
  

  return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <utility>
#include <stack>
using namespace std;

class Graph
{
private:
    int number_of_nodes = 0;
    unordered_map<int, vector<pair<int, int>>> adj_list;
    unordered_map<int, bool> traversed;
    stack<int> s;

public:
    Graph(int no = 0) { number_of_nodes = no; }

    void create_adjacency_list(vector<vector<int>> &edges)
    {
        int n = edges.size();
        int u = 0;
        int v = 1;
        int w = 2;
        for (int i = 0; i < edges.size(); i++)
        {
            pair<int, int> pairs = make_pair(edges[i][v], edges[i][w]);
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
    void printStack()
    {
        while (!s.empty())
        {
            cout << s.top() << "->";
            s.pop();
        }
    }

    void dfs(int node)
    {
        traversed[node] = true;
        const vector<pair<int, int>> &neighbors = adj_list[node];
        for (const auto &neighbor : neighbors)
        {
            if (!traversed[neighbor.first])
            {
                dfs(neighbor.first);
            }
            s.push(node);
            return;
        }
    }

    void find_shortest_distance(int start, int destination)
    {
        vector<int> distances(number_of_nodes, INT16_MAX);
        distances[start] = 0;
        while (!s.empty())
        {   
            int curr_node=s.top();
            if(curr_node==INT16_MAX){
                continue;
            }
            const vector<pair<int, int>> &neighbors = adj_list[curr_node];
            for (const auto &neighbor : neighbors)
            {
                int v = neighbor.first;
                int W=neighbor.second;
                distances[v]=min(distances[v],distances[curr_node]+W);
            }
            s.pop();
        }

        cout<<"\n\n FINAL SOURCE DISTANCES"<<endl;
        for (int i = 0; i < number_of_nodes; i++)
        {
            cout<<distances[i]<<"_______";
        }
        
    }

    
    
};

int main()
{
    Graph g1(6);

    vector<vector<int>> Graph_input = {{0, 1, 5}, {0, 2, 3}, {1, 2, 2}, {1, 3, 6}, {2, 3, 7}, {2, 4, 4}, {2, 5, 2}, {3, 4, -1}, {4, 5, -2}};

    g1.create_adjacency_list(Graph_input);
    g1.print_adjacency_list();

    g1.dfs(0);
    //g1.find_shortest_distance(1,5);

    g1.printStack();
    return 0;
}
#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<queue>
using namespace std;


class Graph{

private:
    int number_of_nodes=0;
    unordered_map<int,vector<int>> adj_list;
    unordered_map<int,bool> visited;
    
public:
    Graph(int no){number_of_nodes=no;}

    void create_adjacency_list(vector<vector<int>> v){
        int n=v.size();
        for(int i=0;i<n;i++){
            adj_list[v[i][0]].push_back(v[i][1]);
        }
    }

    void bfs(int source_node=0){
        queue<int> q;
        vector<bool> traversed(number_of_nodes,false);
        unordered_map<int,int> parent_record;
        parent_record[source_node]=-1;
        q.push(source_node);
        while (!q.empty()){
            int processed_node=q.front();
            
            traversed[processed_node]=true;
            q.pop();
            vector<int> neighbours=adj_list[processed_node];
            for(int i=0;i<neighbours.size();i++){
                
                if(!traversed[neighbours[i]] ){
                    q.push(neighbours[i]);
                    traversed[neighbours[i]]=true;
                    parent_record[neighbours[i]]=processed_node;
                }
                else if(traversed[neighbours[i]] && neighbours[i]!=parent_record[processed_node]){
                       cout<<"Cycle";
                }
            }
            cout<<"TRAVERSED"<<processed_node<<endl;
        }
    }

    void dfs(int node){
        cout<<node;
        visited[node] = true;
        vector<int> neighbours1=adj_list[node];
        for (int i = 0; i < neighbours1.size(); i++)
        {
            if(!visited[neighbours1[i]]){
                dfs(neighbours1[i]);
            }
        }
        
    }

    void dfs_cycle_detection(int node, int parent) {
    cout << node;
    visited[node] = true;
    vector<int> neighbours1 = adj_list[node];
    for (int i = 0; i < neighbours1.size(); i++) {
        if (!visited[neighbours1[i]]) {
            dfs_cycle_detection(neighbours1[i], node);
        } 
        else if (neighbours1[i] != parent) {
            cout << "Cycle detected!" << endl;
        }
    }
}


   void printAdjacencyList() const {
        for (const auto& pair : adj_list) {
            int vertex = pair.first;
            const vector<int>& neighbors = pair.second;

            cout << "Vertex " << vertex << " is connected to: ";
            for (int neighbor : neighbors) {
                cout << neighbor << " ";
            }
            cout << std::endl;
        }
    }
};
    

int main(){
    Graph g1(7);
    vector<vector<int>> Graph_input={{0,1},{0,2},{1,3},{1,4},{2,5},{2,6},{3,7},{3,8},{4,1},{5,2},{6,2},{7,3},{8,3},{7,8},{8,7}};
    
    
    g1.create_adjacency_list(Graph_input);
    //g1.printAdjacencyList();
    //g1.bfs();
    //g1.dfs(0);
    g1.dfs_cycle_detection(0,-1);
  return 0;
}
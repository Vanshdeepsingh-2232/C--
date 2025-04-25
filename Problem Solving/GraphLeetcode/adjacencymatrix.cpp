#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<stack>
using namespace std;

class Graph{

private:
    int number_of_nodes=0;
    vector<vector<int>> Gmatrix;


public:
    Graph(int n) :number_of_nodes(n),Gmatrix(n,vector<int>(n,0)){}
    
    
    inline void add_edges(int u,int v){
        Gmatrix[u][v]=1;
        Gmatrix[v][u]=1;
    }



    inline void remove_edge(int u,int v){
        Gmatrix[u][v]=0;
        Gmatrix[v][u]=0;
    }



    void print_adjacencyMatrix(){
        for (int i = 0; i <number_of_nodes; i++)
        {
            for (int j = 0; j <number_of_nodes; j++)
            {   
                //cout<<" "<<j<<" ";
                cout<<Gmatrix[i][j];
            }
            cout<<endl;
        }
    }


    void bfs_traversal(int source_node=0){
        int n=Gmatrix.size();
        vector<bool> travesed(n,false);
        queue<int> q;
        q.push(source_node);
        while(!q.empty()){
            int processed_node=q.front();
            cout<<processed_node<<"-------------"<<endl;
            q.pop();
            if(travesed[processed_node]) continue;
            
            travesed[processed_node]=true;
            cout<<processed_node<<" "<<endl;

            for(int i=0;i<n;i++){
                if(!travesed[i] && Gmatrix[processed_node][i]){
                    q.push(i);
                }
                continue;
            } 
        }
    }

    void dfs_traversal_using_loops(int source_node=0){
        int n=Gmatrix.size();
        vector<bool> travesed(n,false);
        stack<int> q;
        q.push(source_node);
        while(!q.empty()){
            int processed_node=q.top();
            q.pop();
            if(travesed[processed_node]) continue;
            
            travesed[processed_node]=true;
            cout<<processed_node<<" "<<endl;

            for(int i=0;i<n;i++){
                if(!travesed[i] && Gmatrix[processed_node][i]){
                    q.push(i);
                }
                continue;
            } 
        }
    }
    void bfs_traversal_cycle(int source_node=0){
        int n=Gmatrix.size();
        vector<bool> travesed(n,false);
        queue<pair<int,int>> q;
        q.push({source_node,-1});
        while(!q.empty()){
            int processed_node=q.front().first;
            int its_parent=q.front().first;
            cout<<processed_node<<"-------------"<<endl;
            q.pop();

            if(travesed[processed_node]) continue;
            
            travesed[processed_node]=true;
            cout<<processed_node<<" "<<endl;

            for(int i=0;i<n;i++){
                if(!travesed[i] && Gmatrix[processed_node][i]){
                    q.push({i,processed_node});
                }
                else if(its_parent!=i){
                    cout<<"cycle exists"<<endl;
                }
            } 
        }
    }


    
    ~Graph(){ }
};



int main(){
    Graph g1(8);
    //vector<vector<int>> inputG={{0,1},{1,2},{1,3},{2,1},{2,3},{2,6},{3,1},{3,2},{3,4},{4,3},{4,5},{5,4},{5,6},{6,2},{6,5}};
    vector<vector<int>> inputG = {
        {0, 1}, {1, 2}, {1, 3}, {2, 6}, {3, 4}, {4, 5}, {6, 7}
    };

    for (int i = 0; i < inputG.size(); i++)
    {  g1.add_edges(inputG[i][0],inputG[i][1]);  }
    //g1.dfs_traversal_using_loops();
    g1.print_adjacencyMatrix();
    g1.bfs_traversal();
    
  return 0;
}
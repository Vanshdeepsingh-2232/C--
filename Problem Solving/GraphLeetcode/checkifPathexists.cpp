#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<queue>

using namespace std;

// Input: n = 3, edges = [[0,1],[1,2],[2,0]], source = 0, destination = 2
// Output: true
// Explanation: There are two paths from vertex 0 to vertex 2:
// - 0 → 1 → 2
// - 0 → 2


class Solution {

public:
//     void print_adj_list(unordered_map<int,vector<int>> &adj_list){
//     for(auto it = adj_list.begin(); it != adj_list.end(); ++it){
//         cout << it->first << "{";
//         for(auto neighbor : it->second){
//             cout << neighbor << ",";
//         }
//         cout << "}" << endl;
//     }
// }


    bool validPath(int n, vector<vector<int>>& edges, int source, int destination){
        unordered_map<int,vector<int>> adj_list;
        for(int i=0;i<edges.size();i++){ 
            adj_list[edges[i][0]].push_back(edges[i][1]);
            adj_list[edges[i][1]].push_back(edges[i][0]);
        }


        queue<int> q;
        q.push(source);
        vector<bool> visited(n,false);
        visited[source]=true;
        while (!q.empty())
        {
            int processed_node=q.front();
            q.pop();
            vector <int> v=adj_list[processed_node];
            for(int i=0;i<v.size();i++){
                if(!visited[v[i]]){
                    q.push(v[i]);
                    visited[v[i]]=true;
                }
            }
        }
        if(visited[destination]==true) return true;
        else return false;
    }

};


int main(){
    Solution s1;
    vector<vector<int>> edges={{0,1},{1,2},{2,0},{5,5}};
    int source=0, destination=5, n=6;
    cout<<s1.validPath(n,edges,source,destination);
  return 0;
}
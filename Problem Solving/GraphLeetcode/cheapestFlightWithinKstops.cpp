#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include<unordered_map>
#include <queue>
using namespace std;

// // There are n cities connected by some number of flights.
// // You are given an array flights where flights[i] = [fromi, toi, pricei] indicates
// // that there is a flight from city fromi to city toi with cost pricei.

// // You are also given three integers src, dst, and k, return the cheapest
// // price from src to dst with at most k stops. If there is no such route, return -1.

// class Solution
// {
// private:

//     vector<vector<pair<int, int>>> adj_list;

//     void create_adj_list(vector<vector<int>> &flights)
//     {
//         for (int i = 0; i < flights.size(); i++)
//         {
//             int u = flights[i][0];
//             int v = flights[i][1];
//             int w = flights[i][2];
//             adj_list[u].push_back(make_pair(v, w));
//         }
//     }
//     void printAdjList(const vector<vector<pair<int, int>>> &adj_list)
//     {
//         for (int i = 0; i < adj_list.size(); ++i)
//         {
//             cout << "Node " << i << " -> ";
//             for (const auto &edge : adj_list[i])
//             {
//                 cout << "(" << edge.first << ", " << edge.second << ") ";
//             }
//             cout << endl;
//         }
//     }

// public:
//     int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
//     {
       
//         adj_list.resize(n);
      
//         create_adj_list(flights);

//         vector<int> Stops(n,0);
//         vector<int> D(n, INT16_MAX);
//         queue<pair<int,int>> Q;
//         pair<int,int> p={src,0};
//         Q.push(p);
//         D[src] = 0;
        
//         while (!Q.empty() )
//         {
          
//             auto top = Q.front();
//             Q.pop();

//             for(auto N_c:adj_list[top.first]){
//                 if(N_c.second+D[top.first] < D[N_c.first] && Stops[N_c.first]<k){
//                     D[N_c.first]=N_c.second+D[top.first];
//                     Stops[N_c.first]++;
//                     Q.push(N_c);
//                 }
                
//             }

//         }

//         printAdjList(adj_list);
//         for (int i = 0; i < D.size(); i++)
//         {
//             cout<<D[i]<<"_";
//         }
//         for (int i = 0; i < D.size(); i++)
//         {
//             cout<<Stops[i]<<"_";
//         }
        
//     }
// };

// int main()
// {
//     vector<vector<int>> flights = {{0, 1, 100},
//                                    {1, 2, 100},
//                                    {2, 0, 100},
//                                    {1, 3, 600},
//                                    {2, 3, 200}};

//     Solution s1;
//     s1.findCheapestPrice(4, flights, 0, 3, 1);

//     return 0;
// }

// // Input: n = 4, flights = {{0,1,100},{1,2,100},{2,0,100},{1,3,600},{2,3,200}},
// // src = 0, dst = 3, k = 1
// // Output: 700
// // Explanation:
// // The graph is shown above.
// // The optimal path with at most 1 stop
// // from city 0 to 3 is marked in red and has cost 100 + 600 = 700.
// // Note that the path through cities {0,1,2,3} is cheaper
// // but is invalid because it uses 2 stops.

















//FAR BETTER SOLUTION


class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        unordered_map<int,vector<pair<int,int>>> adj; 
        for(int i=0;i<flights.size();i++){
            int u= flights[i][0];
            int v= flights[i][1];
            int d= flights[i][2];
            adj[u].push_back({v,d});
        }
        queue<pair<int,int>> q;
        vector<int> dist(n,INT_MAX);
        q.push({src,0});
        dist[src]=0;
        
        while(!q.empty() && k-- >=0){
            int len = q.size();
            while(len--){
                auto temp = q.front();
                q.pop();
                int node = temp.first;
                int distance = temp.second;
                for(auto neigh:adj[node]){
                    if(dist[neigh.first]> distance + neigh.second){
                        dist[neigh.first] = distance + neigh.second;
                        q.push({neigh.first,dist[neigh.first]});
                    }
                }
            }
            
        }
        if(dist[dst]==INT_MAX)return -1;
        return dist[dst];
    }
};
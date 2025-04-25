#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution
{

public:
    int find_parent(int node, vector<int> &parent)
    {
        if (parent[node] == node)
        {
            return parent[node];
        }

        return parent[node] = find_parent(parent[node], parent);
    }

    void Union(int u, int v, vector<int> &rank, vector<int> &parent)
    {
        int parent_u = find_parent(u, parent);
        int parent_v = find_parent(v, parent);

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

    vector<int> findRedundantConnection(vector<vector<int>> &edges)
    {
        int n = edges.size();
    
        vector<int> rank(n+1, 0);
        vector<int> parent(n+1);
        vector<vector<int>> ans;

        for (int i = 0; i < n+1; i++) parent[i] = i;

        for (int i = 0; i < n; i++)
        {
            int u=edges[i][0];
            int v=edges[i][1];

            int parent_u=find_parent(u,parent);
            int parent_v=find_parent(v,parent);

            if(parent_u != parent_v){
                Union(parent_u,parent_v,rank,parent);
            }
            else{
                ans.push_back({u,v});
                
            }
        }

        return ans[0];
    }
};

// Input: edges = {{1,2},{2,3},{3,4},{1,4},{1,5}};
// Output: {1,4};

// Input: edges = {{1,2},{1,3},{2,3}}
// Output: [2,3]

int main()
{
    vector<vector<int>> edges = {{1,2},{1,3},{2,3}};
    Solution s1;
    vector<int> ans=s1.findRedundantConnection(edges);
    cout<<"U="<<ans[0]<<"  V="<<ans[1]<<endl;
    return 0;
}
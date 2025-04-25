#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <set>
using namespace std;

class Solution
{
public:
    void dfs(int node, vector<bool> &visited, vector<vector<int>> &isConnected, int n)
    {
        if (visited[node])
            return;
        visited[node] = true;
        for (int i = 0; i < n; i++)
            if (isConnected[node][i] && !visited[i])
                dfs(i, visited, isConnected, n);
    }
    int findCircleNum(vector<vector<int>> &isConnected)
    {
        int ans = 0;
        int n = isConnected.size();
        vector<bool> visited(n, false);
        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                ans++;
                dfs(i, visited, isConnected, n);
            }
        }
        return ans;
    }
};

int main()
{
    // vector<vector<int>> isConnected = {{1, 1, 0},
    //                                    {1, 1, 0},
    //                                    {0, 0, 1}};

    vector<vector<int>> isConnected = {{1, 1, 1},
                                       {1, 1, 1},
                                       {1, 1, 1}};
    Solution s1;
    cout << s1.findCircleNum(isConnected);

    return 0;
}
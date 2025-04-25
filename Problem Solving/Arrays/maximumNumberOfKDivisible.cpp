#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <set>
using namespace std;
// for (auto &i : alist)
// {
//     cout << i.first << "-";
//     for (int j = 0; j < i.second.size(); j++)
//     {
//         cout << i.second[j];
//     }
//     cout << endl;
// }
class Solution
{
public:
    int maxKDivisibleComponents(int n, vector<vector<int>> &edges,
                                vector<int> &values, int k)
    {
        // Step 1: Create adjacency list from edges
        vector<int> adjList[n];
        for (auto edge : edges)
        {
            int node1 = edge[0];
            int node2 = edge[1];
            adjList[node1].push_back(node2);
            adjList[node2].push_back(node1);
        }
        // Step 2: Initialize component count
        int componentCount = 0;

        // Step 3: Start DFS traversal from node 0
        dfs(0, -1, adjList, values, k, componentCount);

        // Step 4: Return the total number of components
        return componentCount;
    }

private:
    int dfs(int currentNode, int parentNode, vector<int> adjList[],
            vector<int> &nodeValues, int k, int &componentCount)
    {
        // Step 1: Initialize sum for the current subtree
        int sum = 0;

        // Step 2: Traverse all neighbors
        for (auto neighborNode : adjList[currentNode])
        {
            if (neighborNode != parentNode)
            {
                // Recursive call to process the subtree rooted at the neighbor
                sum += dfs(neighborNode, currentNode, adjList, nodeValues, k,
                           componentCount);
                sum %= k; // Ensure the sum stays within bounds
            }
        }

        // Step 3: Add the value of the current node to the sum
        sum += nodeValues[currentNode];

        // Step 4: Check if the sum is divisible by k
        sum %= k;
        if (sum == 0)
            componentCount++;

        // Step 5: Return the computed sum for the current subtree
        return sum;
    }
};
int main()
{
    int n = 5;
    vector<vector<int>> edges = {{0, 2}, {1, 2}, {1, 3}, {2, 4}};
    vector<int> values = {1, 8, 1, 4, 4};
    int k = 6;
    Solution s1;
    cout << s1.maxKDivisibleComponents(n, edges, values, k);
    return 0;
}
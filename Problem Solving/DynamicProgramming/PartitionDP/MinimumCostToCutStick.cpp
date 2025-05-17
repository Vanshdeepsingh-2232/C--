#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <set>
#include <stack>
using namespace std;

// class Solution
// {
// public:
//     int solve(vector<int> &cuts, int i, int j, vector<vector<int>> &dp)
//     {
//         if (i > j)
//             return 0;

//         if (dp[i][j] != -1)
//             return dp[i][j];

//         int mini = INT32_MAX;
//         for (int ind = i; ind <= j; ind++)
//         {
//             int cost = cuts[j + 1] - cuts[i - 1] +
//                        solve(cuts, i, ind - 1, dp) +
//                        solve(cuts, ind + 1, j, dp);

//             mini = min(mini, cost);
//         }

//         return dp[i][j] = mini;
//     }
//     int minCost(int n, vector<int> &cuts)
//     {

//         cuts.push_back(0);
//         cuts.push_back(n);

//         sort(cuts.begin(), cuts.end());

//         int m = cuts.size();
//         vector<vector<int>> dp(m, vector<int>(m, -1));

//         return solve(cuts, 1, cuts.size() - 2, dp);
//     }
// };

class Solution
{
public:
    int minCost(int n, vector<int> &cuts)
    {

        cuts.insert(cuts.begin(), 0);
        cuts.push_back(n);

        sort(cuts.begin(), cuts.end());

        int m = cuts.size() - 2;
        vector<vector<int>> dp(m + 2, vector<int>(m + 2, 0));

        for (int i = m; i >= 1; i--)
        {
            for (int j = 1; j <= m; j++)
            {
                int mini = INT32_MAX;
                for (int ind = i; ind <= j; ind++)
                {
                    int cost = cuts[j + 1] - cuts[i - 1] +
                               dp[i][ind - 1] +
                               dp[ind + 1][j];

                    mini = min(mini, cost);
                    dp[i][j] = mini;
                }
            }
        }

        return dp[1][m];
    }
};

int main()
{
    int n = 9;
    vector<int> cuts = {5, 6, 1, 4, 2};

    Solution s1;
    cout << s1.minCost(n, cuts);

    return 0;
}
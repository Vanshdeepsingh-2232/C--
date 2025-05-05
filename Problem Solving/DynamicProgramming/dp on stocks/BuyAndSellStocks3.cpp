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
//     int solve(vector<int> &prices, int i, int buy, int cap, vector<vector<vector<int>>> &dp)
//     {
//         if (cap == 0)
//             return 0;
//         if (i == prices.size())
//             return 0;

//         if (dp[i][buy][cap] != -1)
//             return dp[i][buy][cap];

//         int profit = 0;
//         if (buy)
//             dp[i][buy][cap] = profit = max(-prices[i] + solve(prices, i + 1, 0, cap, dp), 0 + solve(prices, i + 1, 1, cap, dp));
//         else
//             dp[i][buy][cap] = profit = max(prices[i] + solve(prices, i + 1, 1, cap - 1, dp), 0 + solve(prices, i + 1, 0, cap, dp));
//         return dp[i][buy][cap] = profit;
//     }
//     int maxProfit(vector<int> &prices)
//     {
//         int n = prices.size();
//         // 3d Grid for memo of three dependent variables
//         vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, -1)));
//         return solve(prices, 0, 1, 2, dp);
//     }
// };

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();

        vector<vector<int>> prev(2, vector<int>(3, 0));
        vector<vector<int>> curr(2, vector<int>(3, 0));

        // Writing the base case
        for (int i = 0; i < n; i++)
            for (int buy = 0; buy <= 1; buy++)
                prev[buy][0] = 0;

        for (int buy = 0; buy <= 1; buy++)
            for (int cap = 0; cap <= 2; cap++)
                prev[buy][cap] = 0;

        for (int i = n - 1; i >= 0; i--)
        {
            for (int buy = 0; buy <= 1; buy++)
            {
                for (int cap = 1; cap <= 2; cap++)
                {
                    int profit = 0;

                    if (buy)
                        curr[buy][cap] = max(-prices[i] + prev[0][cap], 0 + prev[1][cap]);
                    else
                        curr[buy][cap] = max(prices[i] + prev[1][cap - 1], 0 + prev[0][cap]);
                }
            }

            prev = curr;
        }

        // Answers are always at the intial call which we made to Our Recurrence Function
        return prev[1][2];
    }
};

int main()
{
    vector<int> v = {3, 3, 5, 0, 0, 3, 1, 4};
    Solution s1;
    cout << s1.maxProfit(v);

    return 0;
}
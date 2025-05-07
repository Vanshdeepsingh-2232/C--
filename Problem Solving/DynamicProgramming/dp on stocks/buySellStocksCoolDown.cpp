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
// private:
//     int solve(vector<int> &prices, int i, int buy, vector<vector<int>> &dp)
//     {

//         if (i >= prices.size())
//             return 0;

//         if (dp[i][buy] != -1)
//             return dp[i][buy];
//         if (buy)
//             return dp[i][buy] = max(-prices[i] + solve(prices, i + 1, 0, dp), 0 + solve(prices, i + 1, 1, dp));
//         else
//             return dp[i][buy] = max(prices[i] + solve(prices, i + 2, 1, dp), 0 + solve(prices, i + 1, 0, dp));
//     }

// public:
//     int maxProfit(vector<int> &prices)
//     {
//         int n = prices.size();
//         vector<vector<int>> dp(n + 1, vector<int>(2, -1));
//         return solve(prices, 0, 1, dp);
//     }
// };

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<int>> dp(n + 2, vector<int>(2, 0));

        for (int i = n - 1; i >= 0; i--)
        {
            dp[i][1] = max(-prices[i] + dp[i + 1][0], 0 + dp[i + 1][1]);
            dp[i][0] = max(prices[i] + dp[i + 2][1], 0 + dp[i + 1][0]);
        }

        return dp[0][1];
    }
};

int main()
{
    vector<int> v = {1, 2, 3, 0, 2};

    Solution s1;
    cout << s1.maxProfit(v);

    return 0;
}
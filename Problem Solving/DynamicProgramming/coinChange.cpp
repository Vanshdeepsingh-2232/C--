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
//     int solve(vector<int> &coins, int amount, int i, vector<vector<int>> &dp)
//     {

//         if (i == 0)
//         {
//             if (amount % coins[i] == 0)
//                 return amount / coins[i];
//             else
//                 return INT16_MAX;
//         }
//         if (dp[i][amount] != -1)
//             return dp[i][amount];

//         int nontake = 0 + solve(coins, amount, i - 1, dp);
//         int take = INT32_MAX;
//         if (coins[i] <= amount)
//             take = 1 + solve(coins, amount - coins[i], i, dp);

//         return dp[i][amount] = min(take, nontake);
//     }
//     int coinChange(vector<int> &coins, int amount)
//     {
//         vector<vector<int>> dp(coins.size(), vector<int>(amount + 1, -1));
//         int ans = solve(coins, amount, coins.size() - 1, dp);
//         return ans > amount ? -1 : ans;
//     }
// };

class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        vector<vector<int>> dp(coins.size() + 1, vector<int>(amount + 1, 1e9));

        int n = coins.size();
        for (int t = 0; t <= amount; t++)
        {
            if (t % coins[0] == 0)
                dp[0][t] = t / coins[0];
        }

        for (int i = 1; i < n; i++)
        {
            for (int t = 0; t <= amount; t++)
            {
                int nontake = dp[i - 1][t];
                int take = 1e9;
                if (coins[i] <= t)
                    take = 1 + dp[i][t - coins[i - 1]];
                dp[i][t] = min(take, nontake);
            }
        }

        int ans = dp[n][amount];

        return (ans >= 1e9) ? -1 : ans;
    }
};

int main()
{

    vector<int> coins = {1, 2, 5};
    int amount = 11;

    Solution s1;
    cout << s1.coinChange(coins, amount);

    return 0;
}
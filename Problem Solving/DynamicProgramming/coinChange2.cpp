#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <set>
#include <stack>
using namespace std;

// Recurrsion with memo

// class Solution
// {
// public:
//     int solve(int amount, vector<int> &coins, int i, vector<vector<int>> &dp)
//     {

//         if (i == 0)
//             return (amount % coins[i] == 0);

//         if (dp[i][amount] != -1)
//             return dp[i][amount];

//         int nontake = solve(amount, coins, i - 1, dp);
//         int take = 0;
//         if (coins[i] <= amount)
//             take = solve(amount - coins[i], coins, i, dp);

//         return dp[i][amount] = nontake + take;
//     }
//     int change(int amount, vector<int> &coins)
//     {
//         vector<vector<int>> dp(coins.size() + 1, vector<int>(amount + 1, -1));
//         int i = coins.size() - 1;
//         return solve(amount, coins, i, dp);
//     }
// };

class Solution
{
public:
    int change(int amount, vector<int> &coins)
    {
        int n = coins.size();
        vector<vector<unsigned long long>> dp(n, vector<unsigned long long>(amount + 1, 0));

        for (int t = 0; t <= amount; t++)
            if (t % coins[0] == 0)
                dp[0][t] = 1;

        for (int i = 1; i < n; i++)
        {
            for (unsigned long long t = 0; t <= amount; t++)
            {
                unsigned long long nontake = dp[i - 1][t];
                unsigned long long take = 0;
                if (coins[i] <= t)
                    take = dp[i][t - coins[i]];
                dp[i][t] = nontake + take;
            }
        }

        for (auto i : dp)
        {
            for (auto j : i)
            {
                cout << j << "_";
            }
            cout << " " << endl;
        }

        return dp[n - 1][amount];
    }
};
int main()
{

    int amount = 5;
    vector<int> coins = {1, 2, 5};

    Solution s1;
    cout << s1.change(amount, coins);
    return 0;
}
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
//     long solve(vector<int> &prices, int index, bool buy, vector<vector<int>> &dp)
//     {

//         if (index == prices.size())
//             return 0;

//         if (dp[index][buy] != -1)
//             return dp[index][buy];
//         long profit = 0;
//         if (buy)
//             profit = max(-prices[index] + solve(prices, index + 1, 0, dp), 0 + solve(prices, index + 1, 1, dp));
//         else
//             profit = max(prices[index] + solve(prices, index + 1, 1, dp), 0 + solve(prices, index + 1, 0, dp));
//         return dp[index][buy] = profit;
//     }
//     int maxProfit(vector<int> &prices)
//     {
//         bool buy = 1;
//         int n = prices.size();
//         vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));

//         return solve(prices, 0, buy, dp);
//     }
// };

// MY OPTIMIZATIONS

// class Solution
// {
// public:
//     int maxProfit(vector<int> &prices)
//     {
//         bool buy = 1;
//         int n = prices.size();
//         // vector<vector<long>> dp(n + 1, vector<long>(2, 0));

//         vector<long> prev(2, 0), curr(2, 0);

//         long p1 = 0;
//         long p2 = 0;

//         for (int i = n - 1; i >= 0; i--)
//         {
//             for (int buy = 0; buy <= 1; buy++)
//             {
//                 long profit = 0;
//                 if (buy)
//                     profit = max(-prices[i] + p1, 0 + p2);
//                 else
//                     profit = max(prices[i] + p2, 0 + p1);

//                 curr[buy] = profit;
//             }

//             p1 = curr[0];
//             p2 = curr[1];
//         }

//         return p2;
//     }
// };

// CP SOLUTION FOR THIS

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int profit = 0;
        for (int i = 1; i < prices.size(); i++)
        {
            if (prices[i] > prices[i - 1])
            {
                profit += prices[i] - prices[i - 1];
            }
        }
        return profit;
    }
};

int main()
{
    vector<int> v = {7, 1, 5, 3, 6, 4};
    Solution s1;
    cout << s1.maxProfit(v);
    return 0;
}
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
//     int solve(vector<int> &prices, int fee, int i, int buy)
//     {
//         if (i == prices.size())
//             return 0;
//         int profit = 0;
//         if (buy)
//             profit = max(-prices[i] + solve(prices, fee, i + 1, 0),
//                          0 + solve(prices, fee, i + 1, 1));
//         else
//             profit = max(prices[i] - fee + solve(prices, fee, i + 1, 1),
//                          0 + solve(prices, fee, i + 1, 0));
//         return profit;
//     }

// public:
//     int maxProfit(vector<int> &prices, int fee)
//     {
//         return solve(prices, fee, 0, 1);
//     }
// };

class Solution
{
public:
    int maxProfit(vector<int> &prices, int fee)
    {
        int n = prices.size();

        int n0 = 0;
        int n1 = 0;

        for (int i = n - 1; i >= 0; i--)
        {
            n1 = max(-prices[i] + n0, n1);
            n0 = max(prices[i] - fee + n1, n0);
        }
        return n1;
    }
};

int main()
{

    vector<int> v = {1, 3, 7, 5, 10, 3};
    Solution s1;
    cout << s1.maxProfit(v, 3);
    return 0;
}
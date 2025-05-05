#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <set>
#include <stack>
using namespace std;

class Solution
{
public:
    int maxProfit(int k, vector<int>& prices)
    {
        int n = prices.size();

        vector<vector<int>> prev(2, vector<int>(k+1, 0));
        vector<vector<int>> curr(2, vector<int>(k+1, 0));

        // Writing the base case
        for (int i = 0; i < n; i++)
            for (int buy = 0; buy <= 1; buy++)
                prev[buy][0] = 0;

        for (int buy = 0; buy <= 1; buy++)
            for (int cap = 0; cap <= k; cap++)
                prev[buy][cap] = 0;

        for (int i = n - 1; i >= 0; i--)
        {
            for (int buy = 0; buy <= 1; buy++)
            {
                for (int cap = 1; cap <= k; cap++)
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
    return 0;
}

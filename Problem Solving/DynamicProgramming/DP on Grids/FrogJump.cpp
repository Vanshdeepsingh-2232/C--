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
    int solve(vector<int> &height, vector<int> &dp, int i)
    {
        if (i == 0)
            return 0;

        if (dp[i] != -1)
            return dp[i];
        int l = solve(height, dp, i - 1) + abs(height[i] - height[i - 1]);
        int r = INT32_MAX;
        if (i > 1)
            r = solve(height, dp, i - 2) + abs(height[i] - height[i - 2]);

        return dp[i] = min(l, r);
    }
    int minCost(vector<int> &height)
    {
        vector<int> dp(height.size() + 1, -1);
        return solve(height, dp, height.size() - 1);
    }

    int TabulationSolve(vector<int> &height)
    {

        int n = height.size();
        vector<int> dp(n + 1, 0);
        dp[0] = 0;
        for (int i = 1; i < n; i++)
        {

            int left = dp[i - 1] + abs(height[i] - height[i - 1]);
            int right = INT32_MAX;
            if (i > 1)
                right = dp[i - 2] + abs(height[i] - height[i - 2]);
            dp[i] = min(left, right);
        }

        return dp[n - 1];
    }
    int SpaceSolve(vector<int> &height)
    {

        int n = height.size();
        int curr = 0;
        int prev1 = 0;
        int prev2 = 0;
        for (int i = 1; i < n; i++)
        {

            int left = prev1 + abs(height[i] - height[i - 1]);
            int right = INT32_MAX;
            if (i > 1)
                right = prev2 + abs(height[i] - height[i - 2]);
            curr = min(left, right);
            prev2 = prev1;
            prev1 = curr;
        }

        return curr;
    }
};

int main()
{
    vector<int> v = {30, 20, 50, 10, 40};
    Solution s1;
    cout << s1.TabulationSolve(v);
    return 0;
}
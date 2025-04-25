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
//     int f(vector<int> &nums, int target, int i, vector<vector<int>> &dp, int off)
//     {

//         if (i < 0)
//             return (target == 0);
//         if (target + off < 0 || target + off >= dp[0].size())
//             return 0;
//         if (dp[i][target + off] != -1)
//             return dp[i][target + off];

//         int negeative = f(nums, target - nums[i], i - 1, dp, off);
//         int positive = f(nums, target + nums[i], i - 1, dp, off);

//         return dp[i][target + off] = positive + negeative;
//     }
//     int findTargetSumWays(vector<int> &nums, int target)
//     {
//         int n = nums.size();
//         int ts = 0;
//         for (auto i : nums)
//             ts += i;

//         if (abs(target) > ts)
//             return 0;
//         vector<vector<int>> dp(n, vector<int>(2 * ts + 1, -1));

//         return f(nums, target, n - 1, dp, ts);
//     }
// };
class Solution
{
public:
    int f(vector<int> &arr, int K, int i, vector<vector<int>> &dp)
    {
        if (K < 0)
            return 0;
        if (i == 0)
        {
            if (K == 0 && arr[0] == 0)
                return 2;
            if (K == 0 || arr[0] == K)
                return 1;
            return 0;
        }

        if (dp[i][K] != -1)
            return dp[i][K];
        int nonpick = f(arr, K, i - 1, dp);
        int pick = 0;
        if (arr[i] <= K)
            pick = f(arr, K - arr[i], i - 1, dp);

        return dp[i][K] = pick + nonpick;
    }
    int findTargetSumWays(vector<int> &nums, int target)
    {
        int n = nums.size();
        int ts = 0;
        for (int &i : nums)
            ts += i;
        if (ts - target < 0 || (ts - target) % 2 != 0)
            return false;
        vector<vector<int>> dp(n, vector<int>(target + 1, -1));
        return f(nums, (ts - target) / 2, n - 1, dp);
    }
};

int main()
{
    vector<int> nums = {1, 1, 1, 1, 1};
    int target = 3;

    Solution s1;
    cout << s1.findTargetSumWays(nums, target);
    return 0;
}
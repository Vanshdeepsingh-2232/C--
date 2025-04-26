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

    int findways(vector<int> &num, int tar)
    {
        int n = num.size();

        vector<vector<int>> dp(n, vector<int>(tar + 1, -1));

        return f(num, tar, n - 1, dp);
    }

    int countPartitions(int n, int d, vector<int> &nums)
    {
        int ts = 0;
        for (int &i : nums)
            ts += i;

        if (ts - d < 0 || (ts - d) % 2 != 0)
            return false;

        return findways(nums, (ts - d) / 2);
    }
};

int main()
{

    vector<int> nums = {1, 1, 1, 1, 1};
    int target = 3;

    Solution s1;
    cout << s1.countPartitions(5, 3, nums);
    return 0;
}
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
//     int solve(vector<int> &nums, int i, int prev, vector<vector<int>> &dp)
//     {
//         if (i == nums.size())
//             return 0;

//         if (dp[i][prev + 1] != -1)
//             return dp[i][prev + 1];

//         int take = 0;
//         if (prev == -1 || nums[i] > nums[prev])
//         {
//             take = 1 + solve(nums, i + 1, i, dp);
//         }
//         int nontake = 0;
//         nontake = 0 + solve(nums, i + 1, prev, dp);

//         return dp[i][prev + 1] = max(take, nontake);
//     }

// public:
//     int lengthOfLIS(vector<int> &nums)
//     {
//         int n = nums.size();
//         vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));

//         return solve(nums, 0, -1, dp);
//     }
// };

// class Solution
// {
// public:
//     int lengthOfLIS(vector<int> &nums)
//     {
//         int n = nums.size();
//         vector<int> pre(n + 1, 0);
//         vector<int> curr(n + 1, 0);

//         for (int i = n - 1; i >= 0; i--)
//         {
//             for (int prev = i - 1; prev >= -1; prev--)
//             {
//                 int len = 0;
//                 if (prev == -1 || nums[i] > nums[prev])
//                     len = 1 + pre[i + 1];
//                 len = max(len, 0 + pre[prev + 1]);
//                 curr[prev + 1] = len;
//             }

//             pre = curr;
//         }

//         return pre[-1 + 1];
//     }
// };

// class Solution
// {
// public:
//     int lengthOfLIS(vector<int> &nums)
//     {
//         vector<int> temp;
//         temp.push_back(nums[0]);

//         for (int i = 1; i < nums.size(); i++)
//         {
//             if (nums[i] > temp.back())
//                 temp.push_back(nums[i]);
//             else
//             {
//                 auto lb = lower_bound(temp.begin(), temp.end(), nums[i]);
//                 *lb = nums[i];
//             }
//         }

//         return temp.size();
//     }
// };

class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp(n, 1);
        vector<int> hash(n, 0);
        int maxi = 1;
        int last_i = 0;

        for (int i = 0; i < n; i++)
        {
            hash[i] = i;
            for (int j = 0; j < i; j++)
            {
                if (nums[j] < nums[i] && 1 + dp[j] > dp[i])
                {
                    dp[i] = 1 + dp[j];
                    hash[i] = j;
                }
            }

            if (dp[i] > maxi)
            {
                maxi = dp[i];
                last_i = i;
            }
        }

        vector<int> t;
        t.push_back(nums[last_i]);
        while (hash[last_i] != last_i)
        {
            last_i = hash[last_i];
            t.push_back(nums[last_i]);
        }

        reverse(t.begin(), t.end());
        for (int i : t)
            cout << i << " ";
    }
};

int main()
{
    vector<int> v = {10, 9, 2, 5, 3, 7, 101, 18};
    Solution s1;
    s1.lengthOfLIS(v);
    return 0;
}
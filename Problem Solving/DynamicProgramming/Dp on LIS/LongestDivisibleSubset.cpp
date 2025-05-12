#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <set>
#include <stack>
using namespace std;

// Longest Divisible Subsequence

class Solution
{
public:
    vector<int> largestDivisibleSubset(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());

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
                if ((nums[i] % nums[j] == 0) && (1 + dp[j]) > dp[i])
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
    vector<int> v = {1, 2, 3};

    Solution s1;
    s1.largestDivisibleSubset(v);

    return 0;
}
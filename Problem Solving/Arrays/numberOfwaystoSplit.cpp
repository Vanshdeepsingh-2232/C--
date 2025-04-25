#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <set>
using namespace std;

class Solution
{
public:
    int waysToSplitArray(vector<int> &nums)
    {

        int n = nums.size();
        vector<int> prefix(n, 0);
        vector<int> sufix(n, 0);
        int sum = 0;
        for (int i = 0; i < n; i++)
            prefix[i] = sum += nums[i];
        sum = prefix[n - 1];
        int ans = 0;
        for (int i = 0; i < n-1; i++)
        {
            if (prefix[i] > (sum - prefix[i]))
                ans++;
        }
        return ans;
    }
};

int main()
{
    vector<int> nums = {10, 4, -8, 7};
    Solution s1;
    cout << s1.waysToSplitArray(nums);
    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    vector<int> rearrangeArray(vector<int> &nums)
    {
        vector<int> ans(nums.size());
        int flag = 0;
        int i = 0;
        int j = 1;
        int k = 0;
        while (k < nums.size())
        {
            if (nums[k] > 0)
            {
                ans[i] = nums[k];
                i += 2;
            }
            if (nums[k] < 0)
            {
                ans[j] = nums[k];
                j += 2;
            }
            k++;
        }
        return ans;
    }
};
int main()
{
    vector<int> v = {3, 1, -2, -5, 2, -4};
    Solution s1;
    vector<int> ans = s1.rearrangeArray(v);
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << "_";

    return 0;
}
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
    int maxSubArray(vector<int> &nums)
    {

        int maximum = INT32_MIN;
        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            if (sum > maximum)
                maximum = sum;
            if (sum < 0)
                sum = 0;
        }
        return maximum;
    }
};
int main()
{
    vector<int> nums = {-1};
    Solution s1;
    cout << s1.maxSubArray(nums);
    return 0;
}
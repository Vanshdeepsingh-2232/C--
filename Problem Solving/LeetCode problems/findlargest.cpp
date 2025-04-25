#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int findMaxK(vector<int> &nums)
    {
        vector<int> hash(nums.size(), 0);
        for (int i = 0; i < nums.size(); i++)
        {
            hash[nums[i]] = nums[i];
        }
        int max = -1;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] > 0 && hash[(0 - nums[i])] == (0 - nums[i]) && nums[i] > max)
            {
                max = nums[i];
            }
        }
        return max;
    }


    // int findMaxK(vector<int> &nums){

    // }



};

// Input: nums = [-1,2,-3,3]
// Output: 3
// Explanation: 3 is the only valid k we can find in the array.

//-9,-43,24,-23,-16,-30,-38,-30

int main()
{
    Solution s1;
    vector<int> nums = {-1, 2, -3, 3};
    cout << s1.findMaxK(nums);

    return 0;
}
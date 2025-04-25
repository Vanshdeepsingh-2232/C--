#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int ele = 0;
        int count = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            if (count == 0)
            {
                ele = nums[i];
                count++;
            }
            else if (nums[i] == ele)
            {
                count++;
            }
            else
                count--;
        }

        int c = 0;
        for (int &i : nums)
        {
            if (i == ele)
                c++;
        }
        if (c > (int)(nums.size() / 2))
        {
            return ele;
        }
        else
            return -1;
    }
};

int main()
{
    vector<int> nums = {2, 2, 1, 1, 1, 2, 2};
    Solution s1;
    s1.majorityElement(nums);
    return 0;
}
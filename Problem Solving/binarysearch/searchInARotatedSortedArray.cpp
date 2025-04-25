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
    int search(vector<int> &nums, int target)
    {
        int n = nums.size();
        int i = 0;
        int j = n - 1;

        while (i <= j)
        {
            int mid = i + (j - i) / 2;

            if (nums[mid] == target)
            {
                return mid;
            }
            else if (nums[i] <= nums[mid])
            {
                if (nums[i] <= target && target < nums[mid])
                {
                    j = mid - 1;
                }
                else
                    i = mid + 1;
            }
            else
            {
                if (nums[mid] < target && target <= nums[j])
                {
                    i = mid + 1;
                }
                else
                    j = mid - 1;
            }
        }
        return -1;
    }
};

int main()
{
    int target = 0;
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    Solution s1;
    cout << s1.search(nums, target);
    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    void rev(vector<int> &nums, int s, int e)
    {
        for (int i = s, j = e; i < j; i++, j--)
            swap(nums[i], nums[j]);
    }
    void nextPermutation(vector<int> &nums)
    {
        int n = nums.size();
        int pivot = -1;
        int great = n - 1;

        for (int i = n - 2; i >= 0; i--)
        {
            if (nums[i] < nums[i + 1])
            {
                pivot = i;
                break;
            }
        }
        if (pivot == -1)
        {
            reverse(nums.begin(), nums.end());
            return;
        }
        for (int j = n - 1; j >= 0; j--)
        {
            if (nums[j] > nums[pivot])
            {
                swap(nums[pivot], nums[j]);
                break;
            }
        }
        rev(nums, pivot + 1, n - 1);
    }
};

int main()
{
    vector<int> nums = {2, 4, 1, 7, 5, 0};
    Solution s1;
    s1.nextPermutation(nums);

    for (int i : nums)
        cout << i << " ";
    return 0;
}
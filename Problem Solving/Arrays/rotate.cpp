#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    void rev(vector<int> &nums, int start, int end)
    {
        for (int i = start, j = end; i < j; i++, j--)
            swap(nums[i], nums[j]);
    }
    void rotate(vector<int> &nums, int k)
    {
        k %= nums.size();
        rev(nums, k, nums.size() - 1);
        rev(nums, 0, k - 1);
        reverse(nums.begin(), nums.end());
    }
};

int main()
{
    vector<int> nums = {1, 2};
    int k = 3;
    Solution s1;
    s1.rotate(nums, k);
    for (int &i : nums)
        cout << i;
    return 0;
}
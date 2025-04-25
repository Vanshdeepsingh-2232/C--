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
    int longestOnes(vector<int> &nums, int k)
    {

        int i = 0;
        int j = 0;
        int n = nums.size();
        while (j < n)
        {
            if (nums[j] == 0)
                k--;
            if (k < 0 && nums[i++] == 0)
                k++;
            j++;
        }
        return j - i;
    }
};

int main()
{

    vector<int> nums = {1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0};
    int k = 3;
    vector<int> nums1 = {0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1};
    Solution s1;
    cout << s1.longestOnes(nums1, k);
    return 0;
}
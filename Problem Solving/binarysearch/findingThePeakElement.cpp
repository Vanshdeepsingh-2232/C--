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
    int findPeakElement(vector<int> &nums)
    {
        // int n = nums.size();
        // int i = 0;
        // int j = n - 2;
        // if (n == 1)
        //     return 0;
        // if (n == 2)
        //     return nums[0] > nums[1] ? 0 : 1;
        // while (i <= j)
        // {
        //     int mid = i + (j - i) / 2;
        //     if (nums[mid - 1] < nums[mid] && nums[mid] > nums[mid + 1])
        //         return mid;
        //     else if (nums[mid] < nums[mid + 1])
        //     {
        //         i = mid + 1;
        //     }
        //     else
        //         j = mid - 1;
        // }
    }
};

class Solution
{
public:
    int findPeakElement(vector<int> &nums)
    {
        int n = nums.size();
        int i = 1;
        int j = n - 2;
        if (n == 1)
            return 0;
        else if (nums[0] > nums[1])
            return 0;
        else if (nums[n - 1] > nums[n - 2])
            return n - 1;
        while (i <= j)
        {
            int mid = i + (j - i) / 2;
            if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1])
                return mid;
            else if (nums[mid] > nums[mid - 1])
                i = mid + 1;
            else
                j = mid - 1;
        }
    }
};

int main()
{
    vector<int> v = {1, 2, 1, 3, 5, 6, 4};
    Solution s1;
    cout << s1.findPeakElement(v);
    return 0;
}
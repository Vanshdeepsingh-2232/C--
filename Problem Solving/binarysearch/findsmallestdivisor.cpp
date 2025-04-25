#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <set>
#include <cmath>
using namespace std;

class Solution
{
public:
    int find_div_sum(vector<int> &nums, int mid)
    {
        int sum = 0;
        for (int &i : nums)
            sum += (i + mid - 1) / mid;
        return sum;
    }
    int smallestDivisor(vector<int> &nums, int threshold)
    {
        int i = 1;
        int j = *max_element(nums.begin(), nums.end());
        while (i <= j)
        {
            int mid = i + (j - i) / 2;
            if (find_div_sum(nums, mid) <= threshold)
                j = mid - 1;
            else
                i = mid + 1;
        }
        return i;
    }
};

int main()
{
    vector<int> nums = {1, 2, 5, 9};
    int threshold = 6;
    Solution s1;
    cout << s1.find_div_sum(nums, threshold);
    return 0;
}
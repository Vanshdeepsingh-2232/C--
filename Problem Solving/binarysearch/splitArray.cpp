#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <set>
#include <numeric>
using namespace std;

class Solution
{
public:
    bool isPossible(vector<int> &nums, int k, int mid)
    {
        int n = nums.size();
        int sum = 0;
        int subarrays = 1;

        for (int i = 0; i < n; i++)
        {
            if (sum + nums[i] > mid)
            {
                sum = nums[i];
                subarrays++;
            }
            else
                sum += nums[i];
        }
        return subarrays <= k;
    }
    int splitArray(vector<int> &nums, int k)
    {

        int i = *max_element(nums.begin(), nums.end());
        int j = accumulate(nums.begin(), nums.end(), 0);

        while (i <= j)
        {
            int mid = i + (j - i) / 2;
            if (isPossible(nums, k, mid))
                j = mid - 1;
            else
                i = mid + 1;
        }
        return i;
    }
};

int main()
{
    vector<int> v = {1, 2, 3, 4, 5};
    int k = 2;
    Solution s1;
    cout << s1.splitArray(v, k);
    return 0;
}

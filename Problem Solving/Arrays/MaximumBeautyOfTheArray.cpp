#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution
{
public:
    // approach two : Sort and use the intervals algorithm.
    // int maximumBeauty(vector<int> &nums, int k)
    // {
    //     vector<pair<int, int>> ranges;

    //     // push all the possible ranges
    //     for (int i = 0; i < nums.size(); i++)
    //         ranges.push_back({nums[i] - k, nums[i] + k + 1});

    //     sort(ranges.begin(), ranges.end());

    //     queue<int> q;

    //     for (auto &i : ranges)
    //     {
    //         while (!q.empty() && q.front() <= i.first)
    //             q.pop();

    //         q.push(i.second);
    //     }
    //     return q.size();
    // }

    // approach 1 Sweep line approach
    //  slowest method to do this question
    //  int maximumBeauty(vector<int> &nums, int k)
    //  {
    //      map<int, int> mp;
    //      for (int i = 0; i < nums.size(); i++)
    //      {
    //          int start = nums[i] - k;
    //          int end = nums[i] + k;
    //          mp[start]++;
    //          mp[end + 1]--;
    //      }

    //     for (auto &i : mp)
    //     {
    //         cout << i.first << "=" << i.second << endl;
    //     }
    //     int ans = 0;
    //     int count = 0;
    //     for (auto i : mp)
    //     {
    //         count += i.second;
    //         cout << "Count in " << i.first << " iteration " << count << endl;
    //         if (count > 1)
    //         {
    //             ans = max(ans, count);
    //         }
    //         cout << "The ans after = " << ans << endl;
    //     }
    //     return ans == 0 ? 1 : ans;
    // }

    int B_search(vector<int> &nums, int &t)
    {
        int low = 0;
        int high = nums.size() - 1;
        int result = 0;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (nums[mid] <= t)
            {
                result = mid;
                low = mid + 1;
            }
            else
                high = mid - 1;
        }
        return result;
    }
    int maximumBeauty(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());
        int maxB = 0;
        for (int i = 0; i < nums.size(); i++)
        {

            int x = nums[i];
            int y = x + 2 * k;
            int j = B_search(nums, y);
            maxB = max(maxB, j - i + 1);
        }
        return maxB;
    }
};

int main()
{
    vector<int> nums = {4, 6, 1, 2};
    int k = 2;
    Solution s1;
    cout << s1.maximumBeauty(nums, k);
    return 0;
}

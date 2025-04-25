#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <set>
using namespace std;

class Solution
{
public:
    // most of the code is not working for all the test cases

    //  long long continuousSubarrays(vector<int> &nums)
    //  {
    //      long long ans = 0;
    //      int n = nums.size();
    //      ans += n;
    //      int left = 0;
    //      int right = 1;
    //      int count = 0;
    //      while (right < n)
    //      {
    //          int maximum = left;
    //          if (nums[right] > nums[maximum])
    //              maximum = right;
    //          if (abs(nums[maximum] - nums[right++]) <= 2)
    //              count++;
    //          else
    //              left++;
    //      }
    //      right--;
    //      left++;
    //      while (left < n-1)
    //      {
    //          int maxi = right;
    //          if (nums[left] > nums[maxi])
    //              maxi = left;
    //          if (left == right)
    //              break;
    //          if (abs(nums[maxi] - nums[left]) <= 2)
    //              count++;
    //          left++;
    //      }
    //      ans += count;
    //      return ans;
    //  }

    // answer using the multiset
    // but this does not pass all the test cases

    //  long long continuousSubarrays(vector<int> &nums)
    //  {
    //      long long ans = 0;

    //     int i = 0;

    //     multiset<int> window;

    //     for (int j = 0; j < nums.size(); j++)
    //     {
    //         window.insert(nums[j]);

    //         if (*window.rbegin() - *window.begin() > 2)
    //         {
    //             window.erase(window.find(nums[i]));
    //             i++;
    //         }

    //         ans += j - i + 1;
    //         for (auto &i : window)
    //         {
    //             cout << i << "_";
    //         }
    //         cout << endl;
    //     }

    //     return ans;
    // }

    // my modified approach but this is not valid got (TLE) because of finding maximum every time the window changes
    //  long long continuousSubarrays(vector<int> &nums)
    //  {
    //      long long ans = 0;
    //      int n = nums.size();

    //     int left = 0;                             // Sliding window start
    //     int maxElem = nums[0], minElem = nums[0]; // Track max and min in the window

    //     for (int right = 0; right < n; ++right)
    //     {
    //         // Update max and min for the current window
    //         maxElem = max(maxElem, nums[right]);
    //         minElem = min(minElem, nums[right]);

    //         // If the window is invalid, shrink it from the left
    //         while (maxElem - minElem > 2)
    //         {
    //             left++;
    //             // Recalculate max and min for the updated window
    //             maxElem = *max_element(nums.begin() + left, nums.begin() + right + 1);
    //             minElem = *min_element(nums.begin() + left, nums.begin() + right + 1);
    //         }

    //         // All subarrays ending at `right` and starting from `left` to `right` are valid
    //         ans += (right - left + 1);
    //     }

    //     return ans;
    // }

    long long continuousSubarrays(vector<int> &nums)
    {
        int n = nums.size();
        long long ans=0;
        int left = 0;
        int right = 0;

        while (right < n)
        {
            multiset<int> hp;
            hp.insert(nums[right]);

            
        }
    }
};

int main()
{
    vector<int> nums = {5, 4, 2, 4};
    Solution s1;
    cout << s1.continuousSubarrays(nums);
    return 0;
}
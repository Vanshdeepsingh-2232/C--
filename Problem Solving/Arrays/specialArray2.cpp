#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

// this is the brute force solution

//  class Solution
//  {
//  public:
//      bool solveQuery(int &start, int &end, vector<int> &nums)
//      {
//          bool ans = true;
//          for (int i = start; (i + 1) <= end; i++)
//          {
//              if ((nums[i] % 2 == 0 && nums[i + 1] % 2 == 0) || (nums[i] % 2 != 0 && nums[i+1] % 2 != 0))
//                  ans = false;
//          }
//          return ans;
//      }
//      vector<bool> isArraySpecial(vector<int> &nums, vector<vector<int>> &queries)
//      {
//          vector<bool> ans;
//          for (auto &i : queries)
//          {
//              if (solveQuery(i[0], i[1], nums))
//                  ans.push_back(true);
//              else
//                  ans.push_back(false);
//          }
//          return ans;
//      }
//  };

class Solution
{
public:
    vector<bool> isArraySpecial(vector<int> &nums, vector<vector<int>> &queries)
    {
        int n = nums.size();
        vector<bool> ans;
        vector<int> prefixes(n, 0);

        for (int i = 1; i < n; i++)
        {
            prefixes[i] = prefixes[i - 1];
            if ((nums[i - 1] % 2 == 0 && nums[i] % 2 == 0) || (nums[i - 1] % 2 != 0 && nums[i] % 2 != 0))
                prefixes[i]++;
        }

        for (int i = 0; i < queries.size(); i++)
        {
            int start = queries[i][0];
            int end = queries[i][1];

            int count = prefixes[start] - (end > 0 ? prefixes[end] : 0);
            ans.push_back(count == 0);
        }

        return ans;
    }
};

int main()
{

    // vector<int> nums = {3, 4, 1, 2, 6};
    // vector<vector<int>> queries = {{0, 4}};
    vector<int> nums = {4, 3, 1, 6};
    vector<vector<int>> queries = {{0, 2}, {2, 3}};
    Solution s1;
    vector<bool> v = s1.isArraySpecial(nums, queries);
    for (int i : v)
        cout << i;
    return 0;
}
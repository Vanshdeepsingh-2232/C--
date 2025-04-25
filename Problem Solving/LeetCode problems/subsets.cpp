#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

// Example 1:

// Input: nums = {1,2,3}
// Output: {{},{1},{2},{1,2},{3},{1,3},{2,3},{1,2,3}}
// Example 2:

// Input: nums = {0}
// Output: {{},{0}}

// class Solution {
// public:

//     vector<vector<int>> subsets(vector<int>& nums) {

//     }
// };
void Print_subsets(vector<int> &nums, int i, vector<int> &sets)
{

  if (i >= nums.size())
  {
    return;
  }
  sets[i]=nums[i];
  Print_subsets(nums, i + 1, sets);
  Print_subsets(nums, i - 1, sets);
}

int main()
{
  vector<int> nums = {1, 2, 3};
  int n = nums.size()-1;
  vector<int> sets(pow(2, n), 0);
  Print_subsets(nums, 0, sets);

  for (int i = 0; i < sets.size(); i++)
  {
    cout << sets[i] << "_";
  }
  return 0;
}
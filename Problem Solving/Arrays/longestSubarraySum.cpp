#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;
// this solution is only working for the positive numbers not for the negatives
//  class Solution
//  {
//  public:
//      int lenOfLongestSubarr(vector<int> &arr, int k)
//      {
//          int i = 0;
//          int j = 0;
//          int n = arr.size();
//          int sum = 0;
//          int maxlen = 0;

//         while (j < n)
//         {
//             while (sum > k && i < n)
//             {
//                 sum -= arr[i];
//                 i++;
//             }
//             if (sum == k)
//                 maxlen = max(maxlen, j - i);
//             sum += arr[j];
//             j++;
//         }
//         return maxlen;
//     }
// };
int main()
{
    vector<int> arr = {10, 5, 2, 7, 1, 9};
    int k = 15;
    Solution s1;
    cout << s1.lenOfLongestSubarr(arr, k);
    return 0;
}
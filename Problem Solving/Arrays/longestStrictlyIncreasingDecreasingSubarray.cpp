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
    int longestMonotonicSubarray(vector<int> &nums)
    {
        int n = nums.size();
        int inclen = 1;
        int declen = 1;
        int maxlen = 1;
        for (int i = 1; i < n; i++)
        {
            if (nums[i - 1] < nums[i])
            {
                inclen++;
                declen = 1;
            }
            else if (nums[i - 1] > nums[i])
            {
                declen++;
                inclen = 1;
            }
            else
            {
                inclen = 1;
                declen = 1;
            }
            maxlen = (maxlen, max(inclen, declen));
        }

        return maxlen;
    }
};

int main()
{

    vector<int> v = {1, 4, 3, 3, 2};
    Solution s1;
    cout << s1.longestMonotonicSubarray(v);
    return 0;
}
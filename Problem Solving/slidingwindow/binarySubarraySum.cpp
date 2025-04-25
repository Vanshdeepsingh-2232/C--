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
    int numSubarraysWithSum(vector<int> &nums, int goal)
    {
        int n = nums.size();
        int i = 0;
        int currsum = 0;
        int prefixzeroes = 0;
        int ans = 0;

        for (int j = 0; j < n; j++)
        {
            currsum += nums[j];
            while (i < j && (currsum > goal || nums[i] == 0))
            {
                if (nums[i] == 1)
                    prefixzeroes = 0;
                else
                    prefixzeroes++;
                currsum -= nums[i];
                i += 1;
            }
            if (currsum == goal)
                ans += 1 + prefixzeroes;
        }
        return ans;
    }
};

int main()
{

    vector<int> v = {1, 0, 1, 0, 1};
    int goal = 2;

    Solution s1;
    cout << s1.numSubarraysWithSum(v, goal);
    return 0;
}
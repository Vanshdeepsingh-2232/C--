#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <set>
#include <stack>
using namespace std;

class Solution
{
public:
    int subarraysWithKDistinct(vector<int> &nums, int k)
    {

        vector<bool> map(100000, 0);

        int i = 0;
        int j = 0;
        int n = nums.size();
        int t = k;
        int ans = 0;

        while (i < n)
        {
            while (t)
            {
                if (!map[nums[j]])
                {
                    map[nums[j]] = true;
                    j++;
                    k--;
                }
                else
                {
                    j++;
                }
            }
            ans++;
            t = k;
            if(j==n-1) j=i;
        }

        return ans;
    }
};

int main()
{
    vector<int> v = {1, 2, 1, 2, 3};
    int k = 2;
    Solution s1;
    cout << s1.subarraysWithKDistinct(v, k);
    return 0;
}
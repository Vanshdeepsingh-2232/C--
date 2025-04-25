#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <set>
using namespace std;

// for (auto i : pre)
//     cout << i;
class Solution
{
public:
    int maxWater(vector<int> &arr)
    {
        // code here
        int n = arr.size();
        vector<int> pre(n, 0);
        int m = -1;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] > m)
                m = arr[i];
            pre[i] = m;
        }
        m = -1;
        for (int i = n - 1; i >= 0; i--)
        {
            if (arr[i] > m)
                m = arr[i];
            pre[i] = min(pre[i], m);
        }
        int ans = 0;
        for (int i = 0; i < n; i++)
            ans += pre[i] - arr[i];
        return ans;
    }
};

int main()
{

    vector<int> v = {3, 0, 1, 0, 4, 0, 2};

    Solution s1;
    cout << s1.maxWater(v);
    return 0;
}
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
    int findContentChildren(vector<int> &g, vector<int> &s)
    {

        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int n = g.size();
        int m = s.size();
        int i = 0;
        int j = 0;
        int ans = 0;

        while (i < n && j < m)
        {
            if (s[j] >= g[i])
            {
                ans++;
                i++;
            }
            j++;
        }
        return ans;
    }
};

int main()
{

    vector<int> v = {1, 2};
    vector<int> s = {1, 2, 3};

    Solution s1;
    cout << s1.findContentChildren(v, s);

    return 0;
}
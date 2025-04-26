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
private:
public:
    int minimumDifference(vector<int> &v)
    {
        int n = v.size();
        // find the totalSUM
        int totalsum = 0;
        for (int &i : v)
            totalsum += i;
        int target = totalsum;
        int offset = totalsum;
        vector<vector<bool>> dp(n, vector<bool>(2 * target + 1, 0));
        // Base case that it is possible to generate the target with 0 elements
        for (int i = 0; i < n; i++)
            dp[i][0] = true;
        if (v[0] <= target)
            dp[0][v[0] + offset] = true;
        for (int i = 1; i < n; i++)
        {
            for (int t = 1; t <= target; t++)
            {
                bool nontake = dp[i - 1][t + offset];
                bool take = false;
                if (t >= v[i])
                    take = dp[i - 1][(t - v[i]) + offset];
                dp[i][t + offset] = nontake || take;
            }
        }
        int mini = 1e9;
        for (int s1 = 0; s1 <= target / 2; s1++)
        {
            if (dp[n - 1][s1 + offset])
                mini = min(mini, abs((totalsum - s1) - s1));
        }
        return mini;
    }
};

int main()
{
    vector<int> v = {3, 9, 7, 3};
    Solution s1;
    cout << s1.minimumDifference(v);
    return 0;
}
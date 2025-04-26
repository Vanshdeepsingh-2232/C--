#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <set>
#include <stack>
using namespace std;

// simple DP Solution
// class Solution
// {
// public:
//     int uniquePaths(int m, int n)
//     {
//         vector<vector<int>> dp(m, vector<int>(n, 1));

//         for (int i = 1; i < m; i++)
//         {
//             for (int j = 1; j < n; j++)
//             {
//                 dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
//             }
//         }
//         return dp[m - 1][n - 1];
//     }
// };

// space optimized

class Solution
{
public:
    int uniquePaths(int m, int n)
    {
        vector<int> dp(n, 1);

        for (int i = 1; i < m; i++)
        {
            int ans = 1;
            for (int j = 1; j < n; j++)
            {
                ans = ans + dp[j];
                dp[j] = ans;
            }
        }
        return dp[n - 1];
    }
};

int main()
{
    int m = 3;
    int n = 7;

    Solution s1;
    cout << s1.uniquePaths(m, n);
    return 0;
}
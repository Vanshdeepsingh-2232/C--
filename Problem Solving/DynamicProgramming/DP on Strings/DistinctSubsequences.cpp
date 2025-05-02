#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <set>
#include <stack>
using namespace std;

// class Solution
// {
// public:
//     int solve(int i, int j, string s, string t, vector<vector<int>> &dp)
//     {
//         if (j < 0)
//             return 1;

//         if (i < 0)
//             return 0;

//         if (dp[i][j] != -1)
//             return dp[i][j];

//         if (s[i] == t[j])
//             return dp[i][j] = (solve(i - 1, j - 1, s, t, dp) + solve(i - 1, j, s, t, dp));
//         else
//             return dp[i][j] = solve(i - 1, j, s, t, dp);
//     }

//     int numDistinct(string s, string t)
//     {
//         int i = s.size();
//         int j = t.size();
//         vector<vector<int>> dp(i + 1, vector<int>(j + 1, -1));
//         return solve(i - 1, j - 1, s, t, dp);
//     }
// };

// Tabulation Solution
// class Solution
// {
// public:
//     int numDistinct(string s, string t)
//     {
//         int n = s.size();
//         int m = t.size();
//         vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

//         for (int i = 0; i <= n; i++)
//             dp[i][0] = 1;
//         for (int j = 1; j <= m; j++)
//             dp[0][j] = 0;

//         for (int i = 1; i <= n; i++)
//         {
//             for (int j = 1; j <= m; j++)
//             {
//                 if (s[i - 1] == t[j - 1])
//                     dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
//                 else
//                     dp[i][j] = dp[i - 1][j];
//             }
//         }

//         return dp[n][m];
//     }
// };

// SIMPLE SPACE OPTIMIZATION
// class Solution
// {
// public:
//     int numDistinct(string s, string t)
//     {
//         int n = s.size();
//         int m = t.size();

//         vector<double> prev(m + 1, 0);
//         vector<double> curr(m + 1, 0);

//         prev[0] = curr[0] = 1;
//         for (int i = 1; i <= n; i++)
//         {
//             for (int j = 1; j <= m; j++)
//             {
//                 if (s[i - 1] == t[j - 1])
//                     curr[j] = prev[j - 1] + prev[j];
//                 else
//                     curr[j] = prev[j];
//             }

//             prev = curr;
//         }

//         return (int)prev[m];
//     }
// };

// SUPER SPACE OPTIMIZATION
class Solution
{
public:
    int numDistinct(string s, string t)
    {
        int n = s.size();
        int m = t.size();

        vector<int> prev(m + 1, 0);

        prev[0] = 1;
        for (int i = 1; i <= n; i++)
        {
            for (int j = m; j >= 0; j--)
            {
                if (s[i - 1] == t[j - 1])
                    prev[j] = prev[j - 1] + prev[j];
            }
        }

        return prev[m];
    }
};

int main()
{
    string s = "rabbbit", t = "rabbit";
    Solution s1;
    cout << s1.numDistinct(s, t);

    return 0;
}
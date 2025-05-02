#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <set>
#include <stack>
using namespace std;

// class Solution
//  {
//  public:
//      int solve(int i, int j, string s, string t, vector<vector<int>> &dp)
//      {

//         if (i < 0)
//             return j + 1;
//         if (j < 0)
//             return i + 1;
//         if (dp[i][j] != -1)
//             return dp[i][j];

//         if (s[i] == t[j])
//             return solve(i - 1, j - 1, s, t, dp);

//         else
//         {
//             int a = dp[i][j] = 1 + solve(i, j - 1, s, t, dp);     // Insert Operation
//             int b = dp[i][j] = 1 + solve(i - 1, j, s, t, dp);     // Delete Operation
//             int c = dp[i][j] = 1 + solve(i - 1, j - 1, s, t, dp); // Replace Operation

//             return dp[i][j] = min(c, min(a, b));
//         }
//     }
//     int minDistance(string word1, string word2)
//     {

//         int n = word1.size();
//         int m = word2.size();

//         vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

//         return solve(n - 1, m - 1, word1, word2, dp);
//     }
// };

// class Solution
// {
// public:
//     int minDistance(string s, string t)
//     {

//         int n = s.size();
//         int m = t.size();
//         vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

//         for (int j = 0; j <= m; j++)
//             dp[0][j] = j;
//         for (int i = 1; i <= n; i++)
//             dp[i][0] = i;

//         for (int i = 1; i <= n; i++)
//         {
//             for (int j = 1; j <= m; j++)
//             {
//                 if (s[i - 1] == t[j - 1])
//                     dp[i][j] = dp[i - 1][j - 1];
//                 else
//                     dp[i][j] = 1 + min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1]));
//             }
//         }

//         return dp[n][m];
//     }
// };

class Solution
{
public:
    int minDistance(string s, string t)
    {

        int n = s.size();
        int m = t.size();
        vector<int> prev(m + 1, 0);
        vector<int> curr(m + 1, 0);

        for (int j = 0; j <= m; j++)
            prev[j] = j;

        for (int i = 1; i <= n; i++)
        {
            curr[0] = i;
            for (int j = 1; j <= m; j++)
            {
                if (s[i - 1] == t[j - 1])
                    curr[j] = prev[j - 1];
                else
                    curr[j] = 1 + min(prev[j - 1], min(prev[j], curr[j - 1]));
            }
            prev = curr;
        }

        return prev[m];
    }
};

int main()
{

    string word1 = "horse", word2 = "ros";
    Solution s1;
    cout << s1.minDistance(word1, word2);
    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <set>
#include <stack>
using namespace std;

// Recurrsion + Memoization
// class Solution
// {
// public:
//     int solve(int i, int j, string &text1, string &text2, vector<vector<int>> &dp)
//     {

//         if (i < 0 || j < 0)
//             return 0;

//         if (dp[i][j] != -1)
//             return dp[i][j];
//         // now there can be two possibilities MATCH OR NOT MATCH (similar to sequences take || non take)
//         if (text1[i] == text2[j])
//             return dp[i][j] = 1 + solve(i - 1, j - 1, text1, text2, dp);
//         return dp[i][j] = 0 + max(solve(i - 1, j, text1, text2, dp), solve(i, j - 1, text1, text2, dp));
//     }
//     int longestCommonSubsequence(string text1, string text2)
//     {

//         int n1 = text1.size();
//         int n2 = text2.size();
//         vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, -1));
//         return solve(n1 - 1, n2 - 1, text1, text2, dp);
//     }
// };

class Solution
{
public:
    int longestCommonSubsequence(string text1, string text2)
    {

        int n1 = text1.size();
        int n2 = text2.size();
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));

        for (int i = 1; i <= n1; i++)
        {
            for (int j = 1; j <= n2; j++)
            {
                if (text1[i - 1] == text2[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }

        return dp[n1][n2];
    }
};

int main()
{

    string text1 = "abcde", text2 = "ace";
    Solution s1;
    cout << s1.longestCommonSubsequence(text1, text2);

    return 0;
}
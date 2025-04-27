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
    string reverse(string s)
    {
        for (int i = 0, j = s.size() - 1; i < j; i++, j--)
            swap(s[i], s[j]);
        return s;
    }
    int longestPalindromeSubseq(string s)
    {
        int n = s.size();
        string s2 = reverse(s);

        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (s[i - 1] == s2[j - 1])
                {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                else
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[n][n];
    }
    int minInsertions(string s)
    {
        return s.size() - longestPalindromeSubseq(s);
    }
};

int main()
{

    string s = "leetcode";
    Solution s1;
    cout << s1.minInsertions(s);

    return 0;
}
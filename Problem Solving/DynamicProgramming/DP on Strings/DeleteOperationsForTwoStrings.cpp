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
    int minDistance(string word1, string word2)
    {
        int n1 = word1.size();
        int n2 = word2.size();
        int l = longestCommonSubsequence(word1, word2);
        return (n1 - l) + (n2 - l);
    }
};

int main()
{
    string word1 = "sea", word2 = "eat";
    Solution s1;
    cout << s1.minDistance(word1, word2);

    return 0;
}
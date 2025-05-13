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
    bool compare(string &s1, string &s2)
    {
        int n1 = s1.size();
        int n2 = s2.size();

        int i = 0;
        int j = 0;

        if (n2 > n1)
            return false;

        while (i < n1)
        {
            if (s1[i] == s2[j])
            {
                i++;
                j++;
            }
            else
            {
                i++;
            }
        }

        if (i == n1 && j == n2)
        {
            return true;
        }
        return false;
    }
    int longestStrChain(vector<string> &words)
    {
        int n = words.size();
        sort(words.begin(), words.end(), [](string &s1, string &s2)
             { return s1.size() < s2.size(); });
        vector<int> dp(n, 1);
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (compare(words[i], words[j]))
                {
                    dp[i] = max(1 + dp[j], dp[i]);
                }
            }
            ans = max(ans, dp[i]);
        }

        return ans;
    }
};
int main()
{

    vector<string> words = {"a", "b", "ba", "bca", "bda", "bdca"};
    Solution s1;
    cout << s1.longestStrChain(words);
    return 0;
}
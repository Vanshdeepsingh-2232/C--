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
    int hamD(const string &s1, const string &s2)
    {
        int ans = 0;
        for (int i = 0; i < s1.size(); i++)
            if (s1[i] != s2[i])
                ans++;
        return ans;
    }

public:
    vector<string> getWordsInLongestSubsequence(vector<string> &words, vector<int> &groups)
    {

        int n = words.size();
        vector<int> dp(n, 1);
        vector<int> hash(n, 0);
        int maxi = 1;
        int last_i = 0;
        for (int i = 0; i < n; i++)
        {
            hash[i] = i;
            for (int j = 0; j < i; j++)
            {
                if (groups[j] != groups[i] &&
                    (words[j].size() == words[i].size()) &&
                    hamD(words[j], words[i]) == 1)
                {
                    if (dp[j] + 1 > dp[i])
                    {
                        dp[i] = max(dp[j] + 1, dp[i]);
                        hash[i] = j;
                    }
                    if (dp[i] > maxi)
                    {
                        maxi = dp[i];
                        last_i = i;
                    }
                }
            }
        }

        vector<string> ans;
        ans.push_back(words[last_i]);
        while (hash[last_i] != last_i)
        {
            last_i = hash[last_i];
            ans.push_back(words[last_i]);
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main()
{
    vector<string> words = {"bab", "dab", "cab"};
    vector<int> groups = {1, 2, 2};

    Solution s1;
    auto ans = s1.getWordsInLongestSubsequence(words, groups);
    for (auto i : ans)
        cout << i << "-_-";

    return 0;
}
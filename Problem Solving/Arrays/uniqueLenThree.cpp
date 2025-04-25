#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <set>
using namespace std;

class Solution
{
public:
    int count_unique(int start, int end, string &s)
    {
        int count = 0;
        vector<bool> map(27, false);
        for (int i = start + 1; i < end; i++)
        {
            if (!map[s[i] - 'a'])
                count++;
            map[s[i] - 'a'] = true;
        }
        return count;
    }
    int countPalindromicSubsequence(string s)
    {
        int ans = 0;
        int i = 0;
        int n = s.size();
        vector<bool> map(26, false);
        for (i = 0; i < n - 2; i++)
        {
            if (map[s[i] - 'a'])
                continue;

            int e = 0;
            for (int j = n - 1; j >= 0; j--)
            {
                if (s[j] == s[i] && (j - i + 1) > 3)
                {
                    e = j;
                    map[s[i] - 'a'] = true;
                    break;
                }
            }
            ans += count_unique(i, e, s);
        }
        return ans;
    }
};

int main()
{

    string s = "bbcbaba";
    Solution s1;
    cout << s1.countPalindromicSubsequence(s);
    // cout << s1.count_unique(0, 4, s);
    return 0;
}
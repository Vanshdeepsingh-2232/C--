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
    int lengthOfLongestSubstring(string s)
    {
        unordered_map<char, int> map; // Tracks the last index of each character
        int left = 0; // Left boundary of the sliding window
        int maxlen = 0; // Maximum length of the substring

        for (int i = 0; i < s.size(); i++)
        {
            if (map.count(s[i]) && map[s[i]] >= left)
                left = map[s[i]] + 1;
            map[s[i]] = i;
            maxlen = max(maxlen, i - left + 1);
        }
        return maxlen;
    }
};


int main()
{
    string s = "cdwesdddddd";
    Solution s1;
    cout << s1.lengthOfLongestSubstring(s);
    return 0;
}
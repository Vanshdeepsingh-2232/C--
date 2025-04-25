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
    bool rotateString(string s, string goal)
    {
        int k = 0;
        int n = s.size();
        int g = goal.size();
        if (n != g)
        {
            return false;
        }
        while (s[k] != goal[0] && k < n)
            k++;
        for (int i = 0; i < goal.size(); i++)
        {
            if (goal[i] != s[k])
            {
                return false;
            }
            if (k == n - 1)
            {
                k = 0;
                continue;
            }
            k++;
        }
        return true;
    }
};
class Solution {
public:
    bool rotateString(string s, string goal) {
        // Check if the lengths are different
        if (s.length() != goal.length()) return false;

        // Create a new string by concatenating 's' with itself
        string doubledString = s + s;

        // Use find to search for 'goal' in 'doubledString'
        // If find returns an index that is less than the
        // length of doubledString, 'goal' is a substring
        return doubledString.find(goal) < doubledString.length();
    }
};

int main()
{
    string s = "abcde";
    string t = "cdeab";
    Solution s1;
    cout << s1.rotateString(s, t);
    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <set>
#include <string>
#include <regex>
using namespace std;

class Solution
{
public:
    void trim(string &str)
    {
        while (str[0] == ' ')
            str.erase(str.begin());
        while (str[str.size() - 1] == ' ')
            str.pop_back();
    }
    void reverse_m(string &s, int i, int j)
    {
        for (; i < j; i++, j--)
            swap(s[i], s[j]);
    }
    void remove_space(string &s, int n)
    {
        string st;
        for (int i = 0; i < n; i++)
        {
            if (isalnum(s[i]))
                st.push_back(s[i]);
            if (s[i] == ' ')
            {
                st.push_back(' ');
                while (s[i] == ' ' && i < n)
                    i++;
                i--;
            }
        }
        s = st;
    }
    string reverseWords(string &s)
    {
        trim(s);
        s.push_back(' ');
        int n = s.size();
        int i = 0;
        for (int j = 0; j < n; j++)
        {
            if (isalnum(s[j]))
                continue;

            if (s[j] == ' ')
            {
                reverse_m(s, i, j - 1);
                i = j;
                while (s[j] == ' ' && j < n)
                {
                    j++;
                }
                i++;
            }
        }
        reverse(s.begin(), s.end());
        trim(s);
        remove_space(s, n);
        cout << s;
    }
};

int main()
{
    string s = "  Bob  Loves  Alice   ";
    Solution s1;
    cout << s1.reverseWords(s);
    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <queue>
#include <set>
using namespace std;

// class Solution
// {
// public:
//     int longestUniqueSubstr(string &s)
//     {
//         // code here
//         int n = s.size();
//         set<char> st;
//         int m = 0;
//         for (int i = 0; i < n; i++)
//         {
//             if (st.find(s[i]) == st.end())
//                 st.insert(s[i]);
//             else
//             {
//                 int m1 = st.size();
//                 if (m1 > m)
//                     m = m1;
//                 st.clear();
//                 st.insert(s[i]);
//             }
//         }
//         return m;
//     }
// };

class Solution
{
public:
    int longestUniqueSubstr(string &s)
    {
        int n = s.size();
        unordered_set<int> st;
        int j = 0;
        int m = 0;
        for (int i = 0; i < n; i++)
        {
            while (st.find(s[i]) != st.end())
                st.erase(s[j++]);
            st.insert(s[i]);
            m = max(m, i - j + 1);
        }
        return m;
    }
};

int main()
{
    string s = "hqghumeaylnlfdxfircvscxggbwkfnqduxwfnfozvs";
    // string s = "abcdefabcbb";
    Solution s1;
    cout << s1.longestUniqueSubstr(s);
    return 0;
}
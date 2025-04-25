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
    string removeOuterParentheses(string s)
    {
        string result;
        int balance = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(')
            {
                if (balance > 0)
                {
                    result += s[i];
                }
                balance++;
            }
            else
            {
                balance--;
                if (balance > 0)
                {
                    result += s[i];
                }
            }
        }
        return result;
    }
};

int main()
{
    string s = "(()())(())(()(()))(())";
    // string s = "()()";
    
    Solution s1;
    cout << s1.removeOuterParentheses(s);
    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <stack>
#include <set>

using namespace std;

class Solution
{
public:
    bool canBeValid(string s, string locked)
    {

        int n = s.size();
        if (n % 2 != 0)
            return false;

        stack<int> st_locked;
        stack<int> st_open;

        for (int i = 0; i < n; i++)
        {
            if (locked[i] == '0')
            {
                st_open.push(i);
            }
            else
            {
                if (s[i] == '(')
                {
                    st_locked.push(i);
                }
                else if (s[i] == ')')
                {
                    if (!st_locked.empty())
                    {
                        st_locked.pop();
                    }
                    else if (!st_open.empty() && st_open.top() < i)
                    {
                        st_open.pop();
                    }
                    else
                        return false;
                }
            }
        }

        while (!st_open.empty() && !st_locked.empty() && st_locked.top() < st_open.top())
        {
            st_locked.pop();
            st_open.pop();
        }

        if (!st_locked.empty())
        {
            return false;
        }

        if (st_open.size() % 2 == 0)
            return true;
        return false;
    }
};

int main()
{

    string s = "))()))", locked = "010100";
    Solution s1;
    cout << s1.canBeValid(s, locked);
    return 0;
}
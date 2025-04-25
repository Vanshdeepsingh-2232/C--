#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>
using namespace std;

long repeatedString(string s, long n)
{
    long count = 0, size = s.size();
    if (n == 1)
    {
        if (s[0] == 'a')
            count++;
    }
    if (size == 1)
    {
        if (s[0] == 'a')
        {
            count = n;
        }
        for (int i = 0; i < size; i++)
        {
            if (s[i] == 'a')
            {
                count++;
            }
        }
    }
    else
    {
        string st = "";
        while (st.size() < n)
        {
            st += s;
            cout << st << endl;
        }
        for (int i = 0; i < st.size(); i++)
        {
            if (st[i] == 'a')
            {
                count++;
            }
        }
    }
    return count;
}

int main()
{
    string s = "aba";
    cout << repeatedString("x", 970770);
    return 0;
}
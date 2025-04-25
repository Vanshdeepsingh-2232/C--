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
    string removeOccurrences(string s, string part)
    {

        while (s.find(part) != string::npos)
        {
            int idx = s.find(part);
            s.erase(idx, part.length());
        }
        return s;
    }
};

int main()
{

    string s = "daabcbaabcbc";
    string part = "abc";

    Solution s1;
    cout << s1.removeOccurrences(s, part);

    return 0;
}
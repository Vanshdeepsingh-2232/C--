#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int lengthOfLastWord(string s)
    {

        int i = s.size() - 1;
        int len = 0;
        while (s[i] == ' ')
            i--;

        while (i >= 0)
        {
            if (s[i] == ' ')
                break;
            if (isalpha(s[i--]))
                len++;
        }
        return len;
    }
};

int main()
{
    Solution s1;
    string s = "d ";
    cout << s1.lengthOfLastWord(s);
    return 0;
}
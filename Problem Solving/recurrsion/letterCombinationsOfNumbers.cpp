#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    void backtrack(vector<string> &ans, string &currStr, int index, unordered_map<char, string> &map, string &digits)
    {

        if (index >= digits.size())
        {
            ans.push_back(currStr);
            return;
        }

        string s = map[digits[index]];
        for (int i = 0; i < s.size(); i++)
        {
            currStr.push_back(s[i]);
            backtrack(ans, currStr, index + 1, map, digits);
            currStr.pop_back();
        }
    }
    vector<string> letterCombinations(string digits)
    {
        unordered_map<char, string> map = {
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}};
        vector<string> ans;
        string currStr = "";
        int index = 0;
        backtrack(ans, currStr, index, map, digits);
        return ans;
    }
};

int main()
{
    string digits = "23";
    Solution s1;
    vector<string> v = s1.letterCombinations(digits);
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << endl;
    }

    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <set>
using namespace std;

// class Solution
// {
// public:
//     int solve(vector<string> &words, int &start, int &end)
//     {
//         int count = 0;
//         for (int i = start; i <= end; i++)
//         {
//             string str = words[i];
//             int n = str.size() - 1;
//             if ((str[0] == 'a' || str[0] == 'e' || str[0] == 'i' || str[0] == 'o' || str[0] == 'u'))
//                 if ((str[n] == 'a' || str[n] == 'e' || str[n] == 'i' || str[n] == 'o' || str[n] == 'u'))
//                     count++;
//         }
//         return count;
//     }
//     vector<int> vowelStrings(vector<string> &words, vector<vector<int>> &queries)
//     {
//         vector<int> ans;
//         for (auto &i : queries)
//             ans.push_back(solve(words, i[0], i[1]));
//         return ans;
//     }
// };

class Solution
{
public:
    bool isVowelString(string &str)
    {
        int n = str.size() - 1;
        if ((str[0] == 'a' || str[0] == 'e' || str[0] == 'i' || str[0] == 'o' || str[0] == 'u'))
            if ((str[n] == 'a' || str[n] == 'e' || str[n] == 'i' || str[n] == 'o' || str[n] == 'u'))
                return true;
        return false;
    }
    vector<int> vowelStrings(vector<string> &words, vector<vector<int>> &queries)
    {
        int n = words.size();
        vector<int> prefix(n, 0);
        vector<int> ans;
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            if (isVowelString(words[i]))
            {
                prefix[i] = sum + 1;
                sum++;
            }
            prefix[i] = sum;
        }
        for (auto &i : queries)
            if (i[0] == 0)
                ans.push_back(prefix[i[1]]);
            else
                ans.push_back(prefix[i[1]] - prefix[i[0]]);
        return ans;
    }
};

int main()
{
    vector<string> words = {"aba", "bcb", "ece", "aa", "e"};
    vector<vector<int>> queries = {{0, 2}, {1, 4}, {1, 1}};
    Solution s1;
    vector<int> v = s1.vowelStrings(words, queries);
    for (auto i : v)
        cout << i;
    return 0;
}
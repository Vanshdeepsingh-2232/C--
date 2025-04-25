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
    string frequencySort(string s)
    {
        int n = s.size();
        string ans;
        priority_queue<pair<int, char>> maxH;
        unordered_map<char, int> map;
        for (int i = 0; i < n; i++)
            map[s[i]] += 1;
        for (auto &i : map)
            maxH.push({i.second, i.first});

        while (!maxH.empty())
        {
            auto top = maxH.top();
            for (int i = 0; i < top.first; i++)
                ans += top.second;
            maxH.pop();
        }

        return ans;
    }
};

int main()
{
    string s = "tree";
    Solution s1;
    cout<<s1.frequencySort(s);
    return 0;
}
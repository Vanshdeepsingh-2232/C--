#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

int nonDivisibleSubset(int k, vector<int> s)
{
    unordered_map<int, int> mp;
    for (auto i : s)
    {
        mp[i % k]++;
    }

    for (auto i : mp)
    {
        cout << i.first << "-" << i.second << endl;
    }

    int cnt = 0;
    if (mp[0] > 0)
        cnt++;
    for (int i = 1; i <= k / 2; i++)
    {
        if (i == k - i && mp[i] != 0)
        {
            cnt += 1;
        }
        else
        {
            cnt += max(mp[i], mp[k - i]);
        }
    }
    return cnt;
}

int main()
{
    vector<int> s = {19, 10, 12, 10, 24, 25, 22};
    int k = 4;
    cout << nonDivisibleSubset(k, s);
    return 0;
}
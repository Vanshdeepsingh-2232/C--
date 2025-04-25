#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <set>
#include <string>
#include <stack>
using namespace std;

// bool subsets(vector<int> &v, int i, int target, unordered_map<string, bool> &dp)
// {
//     if (target == 0)
//         return true;
//     if (i == 0)
//         return target == v[0];
//     string key = to_string(i) + "|" + to_string(target);
//     if (dp.find(key) != dp.end())
//         return dp[key];
//     bool nontake = subsets(v, i - 1, target, dp);
//     bool take = false;
//     if (target >= v[i])
//         take = subsets(v, i - 1, target - v[i], dp);
//     return dp[key] = nontake || take;
// }

bool subsets(vector<int> &v, int target, vector<vector<bool>> &dp)
{

    for (int i = 0; i < v.size(); i++)
        dp[i][0] = true;

    if (v[0] <= target)
        dp[0][v[0]] = true;

    for (int i = 1; i < v.size(); i++)
    {
        for (int t = 1; t <= target; t++)
        {
            bool nontake = dp[i - 1][t];
            bool take = false;
            if (t >= v[i])
                take = dp[i - 1][t - v[i]];

            dp[i][t] = nontake || take;
        }
    }
    return dp[v.size() - 1][target];
}

int main()
{

    vector<int> v = {1, 1, 1, 1, 1};
    int target = 3;
    int n = v.size();
    vector<vector<bool>> dp(n, vector<bool>(target + 1, false));

    cout << subsets(v, target, dp);

    return 0;
}
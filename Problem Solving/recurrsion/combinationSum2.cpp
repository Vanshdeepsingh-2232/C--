#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution
{

private:
    void unique_combinations(vector<int> &candi, vector<int> &combination, vector<vector<int>> &result, int target, int index)
    {
        if (target == 0)
            result.push_back(combination);

        if (target <= 0)
            return;
        int prev = -1;
        for (int i = index; i < candi.size(); i++)
        {
            if (candi[i] == prev)
                continue;
            combination.push_back(candi[i]);
            unique_combinations(candi, combination, result, target - candi[i], i + 1);
            combination.pop_back();
            prev = candi[i];
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> result;
        vector<int> combination;
        int index = 0;
        unique_combinations(candidates, combination, result, target, index);
        return result;
    }
};

int main()
{

    Solution s1;
    vector<int> v = {10, 1, 2, 7, 6, 1, 5};
    int target = 8;
    vector<vector<int>> ans = s1.combinationSum2(v, target);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
            cout << ans[i][j];
        cout << endl;
    }
    return 0;
}
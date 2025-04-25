#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution
{
private:
    int sumation(vector<int> &v)
    {
        int sum = 0;
        for (int i = 0; i < v.size(); i++)
            sum += v[i];
        return sum;
    }
    void calculate_the_combinations(vector<int> &candi, vector<int> &combinations, int target, vector<vector<int>> &result, int index)
    {
        if (index == candi.size())
        {
            if (target == 0)
                result.push_back(combinations);
            return;
        }
        if (candi[index] <= target)
        {
            combinations.push_back(candi[index]);
            calculate_the_combinations(candi, combinations, target - candi[index], result, index);
            combinations.pop_back();
        }
        calculate_the_combinations(candi, combinations, target, result, index + 1);
    }

public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<vector<int>> result;
        vector<int> combinations;
        int index = 0;
        calculate_the_combinations(candidates, combinations, target, result, index);
        return result;
    }
};

int main()
{
    Solution s1;
    vector<int> v = {2, 3, 6, 7};
    vector<vector<int>> ans = s1.combinationSum(v, 7);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
            cout << ans[i][j];
        cout << endl;
    }
    return 0;
}
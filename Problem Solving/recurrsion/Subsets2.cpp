#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution
{

private:
    void calc_subsets(int index, vector<int> &nums, vector<int> &subset,
                      vector<vector<int>> &result)
    {
        result.push_back(subset);
        for (int i = index; i < nums.size(); i++)
        {
            if (i != index && nums[i] == nums[i - 1])
                continue;
            subset.push_back(nums[i]);
            calc_subsets(i + 1, nums, subset, result);
            subset.pop_back();
        }
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        vector<int> subset;
        int index = 0;
        calc_subsets(index, nums, subset, result);
        return result;
    }
};

int main()
{

    Solution s1;
    vector<int> v = {1, 2, 2};
    vector<vector<int>> ans = s1.subsetsWithDup(v);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
            cout << ans[i][j];
        cout << endl;
    }
    return 0;
}
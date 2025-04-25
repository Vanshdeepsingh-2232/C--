#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution
{

private:
    void calc_sequences(int index, vector<int> &nums, vector<vector<int>> &result)
    {
        if (index == nums.size())
        {
            result.push_back(nums);
            return;
        }
        for (int i = index; i < nums.size(); i++)
        {
            swap(nums[index], nums[i]);
            calc_sequences(index + 1, nums, result);
            swap(nums[i], nums[index]);
        }
    }

public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> result;
        vector<int> sequence;
        int index = 0;
        calc_sequences(index, nums, result);
        sort(result.begin(), result.end());
        return result;
    }
};

int main()
{
    Solution s1;
    vector<int> v = {1, 2, 3};
    vector<vector<int>> ans = s1.permute(v);

    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
            cout << ans[i][j];
        cout << endl;
    }
    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution
{
private:
    void calcSubsets(vector<int> &a, int s, vector<int> &subset, vector<vector<int>> &result)
    {
        // pushed the subset which is currently generated
        result.push_back(subset);

        // iterate over all the elements of the array and decide for every element to be inserted or not

        for (int i = s; i < a.size(); i++)
        {
            subset.push_back(a[i]);
            calcSubsets(a, i + 1, subset, result);
            subset.pop_back();
        }
    }

public:
    vector<vector<int>> Subsets(vector<int> &A)
    {
        vector<vector<int>> result;
        vector<int> subset;
        calcSubsets(A, 0, subset, result);
        return result;
    }
};

int main()
{
    Solution s1;
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> v = s1.Subsets(nums);
    for (auto &i : v)
    {
        for (int j = 0; j < i.size(); j++)
        {
            cout << i[j];
        }
        cout << endl;
    }

    return 0;
}
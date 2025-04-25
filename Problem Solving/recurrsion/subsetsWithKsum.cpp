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
        {
            sum += v[i];
        }
        return sum;
    }
    vector<int> calculate_required_subset(vector<int> &v, int s, vector<int> &subset, int desired)
    {
        if (sumation(subset) == desired)
        {
            return subset;
        }
        else
        {
            for (int i = s; i < v.size(); i++)
            {
                subset.push_back(v[i]);
                vector<int> result = calculate_required_subset(v, i + 1, subset, desired);
                if (!result.empty())
                {
                    return result;
                }
                subset.pop_back();
            }
        }

        return {};
    }

public:
    vector<int> RequiredSubset(vector<int> &a, int desired)
    {
        vector<int> subset;
        return calculate_required_subset(a, 0, subset, desired);
    }
};

int main()
{

    Solution s1;
    vector<int> v = {1, 2, 3};
    vector<int> ans = s1.RequiredSubset(v, 6);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i];
    }
    return 0;
}
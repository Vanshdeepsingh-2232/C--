#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <set>
using namespace std;

class Solution
{
public:
    // very slow approach
    //  should not be deleting the nodes because for every delete operation
    //  requires logn time and also insertions took logn time
    //  to shaveoff some couple of tenths from the solution we have to use vectors and sorting

    // AP=1
    //  long long findScore(vector<int> &nums)
    //  {
    //      long long score = 0;
    //      set<pair<int, int>> hp;
    //      for (int i = 0; i < nums.size(); i++)
    //          hp.insert({nums[i], i});

    //     while (!hp.empty())
    //     {
    //         auto top = *(hp.begin());
    //         score += top.first;
    //         int t = top.second;
    //         hp.erase(top);
    //         if (t + 1 < nums.size())
    //             hp.erase({nums[t + 1], t + 1});
    //         if (t - 1 >= 0)
    //             hp.erase({nums[t - 1], t - 1});
    //     }
    //     return score;
    // }

    // AP=2
    long long findScore(vector<int> &nums)
    {
        long long score = 0;
        vector<pair<int, int>> hp;
        for (int i = 0; i < nums.size(); i++)
            hp.push_back({nums[i], i});
        sort(hp.begin(), hp.end());

        for (int i = 0; i < hp.size(); i++)
        {
            int ele = hp[i].first;
            int idx = hp[i].second;
            if (nums[idx] >= 0)
            {
                score += ele;
                if (idx + 1 < nums.size())
                    nums[idx + 1] = INT16_MIN;
                if (idx - 1 >= 0)
                    nums[idx - 1] = INT16_MIN;
            }
        }
        return score;
    };
};
int main()
{
    vector<int> nums = {2, 1, 3, 4, 5, 2};
    Solution s1;
    cout << s1.findScore(nums);
    return 0;
}
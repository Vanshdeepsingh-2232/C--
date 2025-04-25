#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <set>
#define P pair<int, int>
using namespace std;

class Solution
{
public:
    vector<int> getFinalState(vector<int> &nums, int k, int multiplier)
    {
        int n = nums.size();
        priority_queue<P, vector<P>, greater<P>> minhp;
        for (int i = 0; i < n; i++)
            minhp.push({nums[i], i});
        while (k--)
        {
            P t = minhp.top();
            minhp.pop();
            t.first = t.first * multiplier;
            minhp.push(t);
        }
        vector<int> ans(n);
        while (!minhp.empty())
        {
            P top = minhp.top();
            ans[top.second] = top.first;
            minhp.pop();
        }
        return ans;
    }
};

int main()
{
    vector<int> nums = {2, 1, 3, 5, 6};
    int k = 5;
    int multiplier = 2;
    Solution s1;
    s1.getFinalState(nums, k, multiplier);
    return 0;
}
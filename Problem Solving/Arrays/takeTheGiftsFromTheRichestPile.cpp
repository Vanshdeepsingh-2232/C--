#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <set>
#include <queue>
#include <cmath>
using namespace std;

class Solution
{
public:
    long long pickGifts(vector<int> &gifts, int k)
    {
        priority_queue<int> mhp;

        for (int &i : gifts)
            mhp.push(i);

        while (k--)
        {
            int ele = mhp.top();
            mhp.pop();
            ele = floor(sqrt(ele));
            mhp.push(ele);
        }
        int ans = 0;
        while (!mhp.empty())
        {
            ans += mhp.top();
            mhp.pop();
        }
        return ans;
    }
};

int main()
{
    vector<int> gifts = {25, 64, 9, 4, 100};
    int k = 4;
    Solution s1;
    cout << s1.pickGifts(gifts, k);
    return 0;
}
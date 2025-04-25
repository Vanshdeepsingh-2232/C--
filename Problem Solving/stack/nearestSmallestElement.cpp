#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <stack>
using namespace std;

class Solution
{
public:
    vector<int> nearestSmallestElement(vector<int> &nums)
    {

        stack<int> st;
        int n = nums.size();
        vector<int> nse(n, 0);

        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && nums[i] <= st.top())
                st.pop();
            if (st.empty())
            {
                nse[i] = -1;
            }
            else
            {
                nse[i] = st.top();
            }
            st.push(nums[i]);
        }
        return nse;
    }
};

int main()
{

    vector<int> v = {4, 5, 2, 10, 8};
    Solution s1;
    vector<int> s = s1.nearestSmallestElement(v);
    for (auto i : s)
        cout << i;

    return 0;
}
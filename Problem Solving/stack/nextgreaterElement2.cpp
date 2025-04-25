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
    vector<int> nextGreaterElements(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> nge(n, 0);
        stack<int> st;
        for (int i = 2 * (n - 1); i >= 0; i--)
        {
            while (!st.empty() && nums[i % n] >= st.top())
                st.pop();
            if (st.empty())
            {
                nge[i % n] = -1;
            }
            else
            {
                nge[i % n] = st.top();
            }
            st.push(nums[i % n]);
        }
        return nge;
    }
};

int main()
{
    vector<int> v = {1, 2, 1};
    Solution s1;
    vector<int> s = s1.nextGreaterElements(v);
    for (auto i : s)
        cout << i;
    return 0;
}
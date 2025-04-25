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
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {
        stack<int> st;
        unordered_map<int, int> map;
        int n2 = nums2.size();
        vector<int> nge(n2, -1);
        for (int i = n2 - 1; i >= 0; i--)
        {
            while (!st.empty() && nums2[i] >= st.top())
                st.pop();
            if (st.empty())
                map[nums2[i]] = -1;
            else
                map[nums2[i]] = st.top();
            st.push(nums2[i]);
        }
        vector<int> ans;
        for (int i = 0; i < nums1.size(); i++)
            ans.push_back(map[nums1[i]]);

        return ans;
    }
};

int main()

{
    vector<int> v = {4, 1, 2};
    vector<int> v2 = {1, 3, 4, 2};
    Solution s1;
    vector<int> ans = s1.nextGreaterElement(v, v2);
    for (auto i : ans)
    {
        cout << i;
    }

    return 0;
}
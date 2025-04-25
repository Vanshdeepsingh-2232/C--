#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <set>
#include <stack>
using namespace std;

class Solution
{
public:
    int sumSubarrayMins(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> pse(n, -1);
        vector<int> nse(n, n);
        stack<int> st;
        const int MOD = 1e9 + 7;

        // finding the previous smallest element from every element
        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && arr[i] <= arr[st.top()])
                st.pop();
            if (!st.empty())
                pse[i] = st.top();
            st.push(i);
        }

        st = stack<int>();

        // finding the next smallest smallest element from every element
        for (int i = n - 1; i >= 0; i--)
        {
            while (!st.empty() && arr[i] < arr[st.top()])
                st.pop();
            if (!st.empty())
                nse[i] = st.top();
            st.push(i);
        }

        long long ans = 0;
        for (int i = 0; i < n; i++)
        {
            ans += (long long)((i - pse[i]) * (nse[i] - i)) * arr[i] % MOD;
            ans %= MOD;
        }

        return ans;
    }
};

int main()
{

    vector<int> v = {3, 1, 2, 4};
    Solution s1;
    cout << s1.sumSubarrayMins(v);
    return 0;
}
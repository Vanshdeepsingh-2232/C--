#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <set>
using namespace std;

class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &arr)
    {
        // code here

        int n = arr.size();
        vector<int> prefix(n, 1);
        vector<int> suffix(n, 1);

        prefix[0] = arr[0];
        suffix[n - 1] = arr[n - 1];
        for (int i = 1, j = n - 2; i < n; i++, j--)
        {
            prefix[i] *= (prefix[i - 1] * arr[i]);
            suffix[j] *= (suffix[j + 1] * arr[j]);
        }
        // for (auto i : prefix)
        // {
        //     cout << i << "_";
        // }
        // cout << endl;
        // for (auto i : suffix)
        // {
        //     cout << i << "_";
        // }
        // cout << endl;
        vector<int> res;

        for (int i = 0; i < n; i++)
        {
            if (i == 0)
                res.push_back(suffix[i + 1]);
            else if (i == n - 1)
                res.push_back(prefix[n - 2]);
            else
                res.push_back((prefix[i - 1] * suffix[i + 1]));
        }
        return res;
    }
};

int main()
{

    vector<int> v = {10, 3, 5, 6, 2};
    Solution s1;
    vector<int> c = s1.productExceptSelf(v);
    for (auto i : c)
        cout << i << "_";

    return 0;
}
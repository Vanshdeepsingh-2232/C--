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
    int b_search(vector<int> &v)
    {

        int n = v.size();
        int i = 0;
        int j = n - 1;
        int mini = INT32_MAX;
        while (i <= j)
        {
            int mid = (int)(i + j) / 2;
            if (v[mid] == 1)
                j = mid - 1;
            else
                i = mid + 1;

            mini = min(mini, j + 1);
        }
        return mini;
    }
    int rowWithMax1s(vector<vector<int>> &arr)
    {
        int n = arr.size();
        int maxi = INT32_MAX;
        int ind = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            int c = b_search(arr[i]);
            if (c < maxi)
            {
                maxi = c;
                ind = i;
            }
            else if (c == maxi && i < ind)
            {
                ind = i;
            }
        }
        return ind;
    }
};

int main()
{
    vector<vector<int>> mat = {{0, 0, 0, 1, 1, 1, 1, 1, 1},
                               {1, 1, 1, 1, 1, 1, 1, 1, 1},
                               {0, 0, 0, 0, 0, 1, 1, 1, 1},
                               {1, 1, 1, 1, 1, 1, 1, 1, 1}};

    // [ [ 0, 0, 0, 1, 1, 1, 1, 1, 1 ],
    //   [ 1, 1, 1, 1, 1, 1, 1, 1, 1 ],
    //   [ 0, 0, 0, 0, 0, 1, 1, 1, 1 ],
    //   [ 0, 0, 0, 0, 1, 1, 1, 1, 1 ],
    //   [ 0, 0, 0, 0, 0, 0, 1, 1, 1 ],
    //   [ 1, 1, 1, 1, 1, 1, 1, 1, 1 ],
    //   [ 0, 0, 0, 0, 0, 1, 1, 1, 1 ],
    //   [ 1, 1, 1, 1, 1, 1, 1, 1, 1 ],
    //   [ 0, 1, 1, 1, 1, 1, 1, 1, 1 ] ]

        Solution s1;
    cout << s1.rowWithMax1s(mat);
    return 0;
}
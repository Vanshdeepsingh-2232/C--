#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

// Input: mat = {{1,2,3},{4,5,6},{7,8,9}}
// Output: {1,2,4,7,5,3,6,8,9}

class Solution
{
public:
    vector<int> findDiagonalOrder(vector<vector<int>> &mat)
    {
        int m = mat.size();
        int n = mat[0].size();
        vector<int> ans;

        int i = 0;
        int j = 0;
        bool up = 1;

        while (i < m && j < n)
        {
            if (up == true)
            {
                while (i > 0 && j < n - 1)
                {
                    ans.push_back(mat[i][j]);
                    i--;
                    j++;
                }
                ans.push_back(mat[i][j]);
                if (j == n - 1)
                {
                    i++;
                }
                else
                {
                    j++;
                }
            }
            else
            {
                while (i < m - 1 && j > 0)
                {
                    ans.push_back(mat[i][j]);
                    i++;
                    j--;
                }
                ans.push_back(mat[i][j]);
                if (i == m - 1)
                {
                    j++;
                }
                else
                {
                    i++;
                }
            }

            up = !up;
        }

        return ans;
    }
};

int main()
{
    vector<vector<int>> mat = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    Solution s1;
    vector<int> ans = s1.findDiagonalOrder(mat);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << "_";
    }

    return 0;
}
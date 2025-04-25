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
    int findMaxInRow(vector<vector<int>> &mat, int n, int m, int mid)
    {
        int maxI = 0;
        int ind = 0;
        for (int i = 0; i < n; i++)
        {
            if (mat[i][mid] > maxI)
            {
                ind = i;
                maxI = mat[i][mid];
            }
        }
        return ind;
    }
    vector<int> findPeakGrid(vector<vector<int>> &mat)
    {

        int n = mat.size();
        int m = mat[0].size();
        int i = 0;
        int j = m - 1;

        while (i <= j)
        {
            int mid = (i + j) / 2;

            int row = findMaxInRow(mat, n, m, mid);
            int left = mid >= 0 ? mat[row][mid - 1] : -1;
            int right = mid + 1 < m ? mat[row][mid + 1] : -1;

            if (mat[row][mid] > left && mat[row][mid] > right)
                return {row, mid};
            else if (mat[row][mid] < left)
                j = mid - 1;
            else
                i = mid + 1;
        }
        return {-1, -1};
    }
};

int main()
{
    vector<vector<int>> mat = {{10, 20, 15},
                               {21, 30, 14},
                               {7, 16, 32}};

    Solution s1;
    s1.findPeakGrid(mat);
    return 0;
}
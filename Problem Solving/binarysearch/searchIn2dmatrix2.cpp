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
    bool find_num(vector<vector<int>> &matrix, int &target, int i, int j, int n, int m)
    {
        if (i >= n || j < 0)
            return false;
        if (matrix[i][j] == target)
            return true;
        else if (matrix[i][j] > target)
            return find_num(matrix, target, i, j - 1, n, m);
        else
            return find_num(matrix, target, i + 1, j, n, m);
    }
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int n = matrix.size();
        int m = matrix[0].size();
        int i = 0;
        int j = m - 1;
        return find_num(matrix, target, i, j, n, m);
    }
};

int main()
{
    vector<vector<int>> matrix = {{1, 4, 7, 11, 15},
                                  {2, 5, 8, 12, 19},
                                  {3, 6, 9, 16, 22},
                                  {10, 13, 14, 17, 24},
                                  {18, 21, 23, 26, 30}};

    Solution s1;
    int target = 94;
    cout << s1.searchMatrix(matrix, target);
    return 0;
}
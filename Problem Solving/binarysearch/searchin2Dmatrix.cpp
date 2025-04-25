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
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int n = matrix.size();
        int m = matrix[0].size();
        int i = 0;
        int j = n * m - 1;
        while (i <= j)
        {
            int mid = i + (j - i) / 2;
            int row = mid / n;
            int col = mid % m;
            if (matrix[row][col] == target)
                return true;
            else if (matrix[row][col] < target)
                i = mid + 1;
            else
                j = mid - 1;
        }
        return false;
    }
};

int main()
{
    vector<vector<int>> v = {{1, 1}};
    int target = 1;
    Solution s1;
    cout << s1.searchMatrix(v, target);

    return 0;
}
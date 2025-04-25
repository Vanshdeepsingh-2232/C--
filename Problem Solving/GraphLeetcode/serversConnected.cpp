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
    int countServers(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();

        vector<int> row(m, 0);
        vector<int> col(n, 0);

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1)
                {
                    row[i]++;
                    col[j]++;
                }
            }
        }
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1)
                {
                    count += (row[i] > 1 || col[j] > 1);
                }
            }
        }
        return count;
    }
};

int main()
{
    vector<vector<int>> grid = {{1, 0},
                                {1, 1}};

    Solution s1;
    cout << s1.countServers(grid);
    return 0;
}
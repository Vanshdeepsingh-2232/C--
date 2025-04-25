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
    bool inBounds(int n, int m, int i, int j)
    {
        if (i > n - 1 || j > m - 1 || i < 0 || j < 0)
            return false;
        return true;
    }
    int dfs(vector<vector<int>> &grid, vector<vector<bool>> &visited, int i, int j, vector<pair<int, int>> &directions, int &n, int &m)
    {

        visited[i][j] = true;
        int sum = grid[i][j];
        for (pair<int, int> &d : directions)
        {
            if (inBounds(n, m, i + d.first, j + d.second) && !visited[i + d.first][j + d.second] && grid[i + d.first][j + d.second] > 0)
                sum += dfs(grid, visited, i + d.first, j + d.second, directions, n, m);
        }

        return sum;
    }
    int findMaxFish(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] > 0 && !visited[i][j])
                {
                    int sum = dfs(grid, visited, i, j, directions, n, m);
                    ans = max(ans, sum);
                }
            }
        }
        return ans;
    }
};

int main()
{
    vector<vector<int>> grid = {{0, 2, 1, 0},
                                {4, 0, 0, 3},
                                {1, 0, 0, 4},
                                {0, 3, 2, 0}};
    Solution s1;
    cout << s1.findMaxFish(grid);
    return 0;
}
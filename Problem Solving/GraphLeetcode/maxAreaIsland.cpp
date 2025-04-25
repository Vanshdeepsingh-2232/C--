#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution
{

private:
    const vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int bfs(pair<int, int> &S, vector<vector<int>> &grid)
    {
        int number_of_nodes_in_component = 0;
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, int>> Q;
        Q.push(S);
        grid[S.first][S.second]=0;
        while (!Q.empty())
        {
            auto top = Q.front();
            Q.pop();
            
            number_of_nodes_in_component += 1;
            for (auto dir : directions)
            {
                int ni = top.first + dir.first;
                int nj = top.second + dir.second;

                if (ni >= 0 && ni < n && nj >= 0 && nj < m && grid[ni][nj] == 1)
                {
                    Q.push(make_pair(ni, nj));
                    grid[ni][nj]=0;
                }
            }
        }
        return number_of_nodes_in_component;
    }

public:
    int maxAreaOfIsland(vector<vector<int>> &grid)
    {
        int ans = 0;
        int n = grid.size();
        int m = grid[0].size();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1)
                {
                    pair<int, int> source = {i, j};
                    int temp = bfs(source, grid);
                    cout << "temp= " << temp;
                    if (temp > ans)
                        ans = temp;
                }
                continue;
            }
        }
        return ans;
    }
};

// testcase
// {{1,1,0,0,0},
//  {1,1,0,0,0},
//  {0,0,0,1,1},
//  {0,0,0,1,1}}
int main()
{
    Solution s1;
    vector<vector<int>> grid = {{1, 1, 0, 0, 0},
                                {1, 1, 0, 0, 0},
                                {0, 0, 0, 1, 1},
                                {0, 0, 0, 1, 1}};
    s1.maxAreaOfIsland(grid);
    return 0;
}
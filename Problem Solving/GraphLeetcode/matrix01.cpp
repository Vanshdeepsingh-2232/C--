#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <set>
using namespace std;

// basicaly find the nearest ZERO
class Solution
{
public:
    vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
    {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> ans(n, vector<int>(m, INT32_MAX));
        queue<pair<int, int>> q;
        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (mat[i][j] == 0)
                {
                    ans[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        while (!q.empty())
        {
            auto [x, y] = q.front();
            q.pop();
            for (auto &d : directions)
            {
                int nx = x + d.first;
                int ny = y + d.second;

                if (nx >= 0 && nx < n && ny >= 0 && ny < m)
                {

                    if (ans[nx][ny] > ans[x][y] + 1)
                    {
                        ans[nx][ny] = ans[x][y] + 1;
                        q.push({nx, ny});
                    }
                }
            }
        }
        return ans;
    }
};

int main()
{

    // vector<vector<int>> mat = {{0, 0, 0},
    //                            {0, 1, 0},
    //                            {0, 0, 0}};

    vector<vector<int>> mat = {{0, 0, 0},
                               {0, 1, 0},
                               {1, 1, 1}};
    Solution s1;
    vector<vector<int>> m = s1.updateMatrix(mat);
    for (auto i : m)
    {
        for (auto j : i)
            cout << j;
        cout << endl;
    }

    return 0;
}
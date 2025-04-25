#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <set>
#include <stack>
using namespace std;

class Solution
{

private:
    int fresh = 0;
    vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    bool inBounds(int i, int j, int n, int m)
    {
        if (i >= 0 && i < n && j >= 0 && j < m)
            return true;
        return false;
    }

public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        queue<pair<pair<int, int>, int>> q;
        int minutes = 0;
        int n = grid.size();
        int m = grid[0].size();

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 2)
                    q.push({{i, j}, 0});
                if (grid[i][j] == 1)
                    fresh++;
            }
        }

        while (!q.empty())
        {
            auto t = q.front();
            q.pop();

            for (auto d : directions)
            {
                int i = t.first.first + d.first;
                int j = t.first.second + d.second;
                if (inBounds(i, j, n, m) && grid[i][j] == 1)
                {
                    grid[i][j] = 2;
                    fresh--;
                    q.push({{i, j}, t.second + 1});
                    minutes = max(minutes, t.second + 1);
                }
            }
        }
        if (fresh > 0)
            return -1;
        else
            return minutes;
    }
};

int main()
{
    vector<vector<int>> v = {{2, 1, 1},
                             {0, 1, 1},
                             {1, 0, 1}};

    Solution s1;
    cout << s1.orangesRotting(v);

    return 0;
}
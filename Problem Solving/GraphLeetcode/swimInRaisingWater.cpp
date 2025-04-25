
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <set>
using namespace std;

class Solution
{
private:
    const vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    void printSet(const set<pair<int, pair<int, int>>> &SET_STRUCT)
    {
        for (const auto &element : SET_STRUCT)
        {
            cout << "(" << element.first << ", (" << element.second.first << ", " << element.second.second << "))\n";
        }
    }

public:
    int swimInWater(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int time = 0;
        pair<int, int> source = {0, 0};
        set<pair<int, pair<int, int>>> SET_STRUCT;

        SET_STRUCT.insert({grid[0][0], {0, 0}});

        while (!SET_STRUCT.empty())
        {
            auto top = *(SET_STRUCT.begin());
            int W = top.first;
            if (W > time)
                time = W;
            pair<int, int> coordinates = top.second;
            int c1 = coordinates.first;
            int c2 = coordinates.second;
            grid[c1][c2] = -2;
            if (c1 == n - 1 && c2 == n - 1)
            {
                break;
            }
            SET_STRUCT.erase(top);
            for (const auto &dir : directions)
            {
                int ni = c1 + dir.first;
                int nj = c2 + dir.second;

                // Check if the new position is within bounds
                if (ni >= 0 && ni < n && nj >= 0 && nj < n && grid[ni][nj] != -2)
                {
                    SET_STRUCT.insert({grid[ni][nj], {ni, nj}});
                }
            }
        }

        return time;
    }
};
// Input: grid = {{0,1,2,3,4},{24,23,22,21,5},{12,13,14,15,16},{11,17,18,19,20},{10,9,8,7,6}}
// Output: 16
// Explanation: The final route is shown.
// We need to wait until time 16 so that (0, 0) and (4, 4) are connected.

int main()
{
    vector<vector<int>> grid = {{0, 1, 2, 3, 4},
                                {24, 23, 22, 21, 5},
                                {12, 13, 14, 15, 16},
                                {11, 17, 18, 19, 20},
                                {10, 9, 8, 7, 6}};

    Solution s1;
    cout << s1.swimInWater(grid);

    return 0;
}

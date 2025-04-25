#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

// Example 2:
// Input: grid = {{0,0,0},{1,1,0},{1,1,0}}
// Output: 4

class Solution {
private:
    const vector<pair<int, int>> directions = {
        {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}, {-1, 0}, {-1, 1}};

public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        //NxN MATRIX
        int n = grid.size();


        //SIMPLE EDGE CASE
        if (grid[0][0] == 1) {
            return -1;
        }

        //STORE THE CELLS
        queue<pair<int, pair<int, int>>> Q;
        //PUSH THE SOURCE NODE
        Q.push({1,{0,0}});

        while (!Q.empty()) {

            auto top = Q.front();
            Q.pop();

            int d = top.first;
            int x1 = top.second.first;
            int y1 = top.second.second;
            
            grid[x1][y1] = d;

            if (x1 == n - 1 && y1 == n - 1) {
                return d;
            }
            for (auto& dir : directions) {
                int ni_x = x1 + dir.first;
                int ni_y = y1 + dir.second;
                if (ni_x >= 0 && ni_x < n && ni_y >= 0 && ni_y < n &&
                    grid[ni_x][ni_y] == 0) {
                    Q.push({d + 1, {ni_x, ni_y}});
                    grid[ni_x][ni_y] = -1;
                }
            }
        }

        return -1;
    }
};

int main()
{
    vector<vector<int>> grid = {{0, 0, 0},
                                {1, 1, 0},
                                {1, 1, 0}};

    Solution s1;
    cout<<s1.shortestPathBinaryMatrix(grid);
    cout<<endl;
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid.size(); j++)
        {
            cout<<grid[i][j]<<"_";
        }

        cout<<endl;
        
    }
    
    return 0;
}
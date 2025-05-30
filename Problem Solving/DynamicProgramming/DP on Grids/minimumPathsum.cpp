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
public:
    int minPathSum(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));

        dp[0][0] = grid[0][0];

        for (int i = 1; i < m; i++)
            dp[i][0] = dp[i - 1][0] + grid[i][0];

        for (int i = 1; i < n; i++)
            dp[0][i] = dp[0][i - 1] + grid[0][i];

        for (int i = 1; i < m; i++)
            for (int j = 1; j < n; j++)
                dp[i][j] = min(grid[i][j] + dp[i - 1][j], grid[i][j] + dp[i][j - 1]);

        return dp[m - 1][n - 1];
    }
};

int main()
{

    vector<vector<int>> v = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};

    Solution s1;
    cout << s1.minPathSum(v);

    return 0;
}

// for (int i = 0; i < m; i++)
//         {
//             for (int j = 0; j < n; j++)
//             {
//                 cout << dp[i][j];
//             }
//             cout << endl;
//         }
//         cout << endl;
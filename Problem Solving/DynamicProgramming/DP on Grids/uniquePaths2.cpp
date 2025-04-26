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
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();

        vector<int> dp(m, 0);
        dp[0] = obstacleGrid[0][0] == 0 ? 1 : 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {

                if (obstacleGrid[i][j] == 1)
                {
                    dp[j] = 0;
                }
                else if (j > 0)
                {
                    dp[j] += dp[j - 1];
                }
            }
        }

        return dp[n - 1];
    }
};

int main()
{

    vector<vector<int>> v = {{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};

    Solution s1;
    cout << s1.uniquePathsWithObstacles(v);
    return 0;
}
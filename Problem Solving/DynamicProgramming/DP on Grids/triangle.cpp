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
    int minimumTotal(vector<vector<int>> &triangle)
    {
        int m = triangle.size();
        for (int i = m - 2; i >= 0; i--)
        {
            for (int j = 0; j < triangle[i].size(); j++)
            {
                triangle[i][j] = min(triangle[i][j] + triangle[i + 1][j], triangle[i][j] + triangle[i + 1][j + 1]);
            }
        }
        return triangle[0][0];
    }
};

int main()
{

    vector<vector<int>> v = {{2},
                             {3, 4},
                             {6, 5, 7},
                             {4, 1, 8, 3}};

    Solution s1;
    cout << s1.minimumTotal(v);
    return 0;
}
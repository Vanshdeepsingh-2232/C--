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
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        vector<int> ans;

        int n = matrix.size();
        int m = matrix[0].size();

        int top = 0;
        int bottom = n - 1;

        int left = 0;
        int right = m - 1;

        int direction = 0;

        while (left <= right && top <= bottom)
        {
            if (direction == 0)
            {
                for (int col = left; col <= right; col++)
                    ans.push_back(matrix[top][col]);
                direction = 1;
                top++;
            }
            else if (direction == 1)
            {
                for (int row = top; row <= bottom; row++)
                    ans.push_back(matrix[row][right]);
                direction = 2;
                right--;
            }

            else if (direction == 2)
            {
                for (int col = right; col >= left; col--)
                    ans.push_back(matrix[bottom][col]);
                direction = 3;
                bottom--;
            }

            else if (direction == 3)
            {
                for (int row = bottom; row >= top; row--)
                    ans.push_back(matrix[row][left]);
                direction = 0;
                left++;
            }
        }
        return ans;
    }
};

int main()
{

    vector<vector<int>> v = {{1, 2, 3},
                             {4, 5, 6},
                             {7, 8, 9}};

    Solution s1;
    vector<int> a = s1.spiralOrder(v);
    for (int i : a)
        cout << i;

    return 0;
}
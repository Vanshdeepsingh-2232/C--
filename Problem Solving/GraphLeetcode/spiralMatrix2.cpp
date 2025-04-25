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
    vector<vector<int>> generateMatrix(int n)
    {
        vector<vector<int>> matrix(n, vector<int>(n, 0));

        int l = n * n;
        int var = 1;

        int top = 0;
        int bottom = n - 1;

        int left = 0;
        int right = n - 1;

        int direction = 0;

        while (left <= right && top <= bottom)
        {
            if (direction == 0)
            {
                for (int col = left; col <= right; col++)
                    matrix[top][col] = var++;
                direction = 1;
                top++;
            }
            else if (direction == 1)
            {
                for (int row = top; row <= bottom; row++)
                    matrix[row][right] = var++;
                direction = 2;
                right--;
            }

            else if (direction == 2)
            {
                for (int col = right; col >= left; col--)
                    matrix[bottom][col] = var++;
                direction = 3;
                bottom--;
            }

            else if (direction == 3)
            {
                for (int row = bottom; row >= top; row--)
                    matrix[row][left] = var++;
                direction = 0;
                left++;
            }
        }

        return matrix;
    }
};

int main()
{

    Solution s1;
    vector<vector<int>> ans = s1.generateMatrix(3);
    for (auto i : ans)
    {
        for (auto j : i)
            cout << j;
        cout << endl;
    }

    return 0;
}
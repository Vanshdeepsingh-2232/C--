#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

// Input: matrix = {{0,1,2,0},
// {3,4,5,2},
// {1,3,1,5}}
// Output: {{0,0,0,0},{0,4,5,0},{0,3,1,0}}

// LESSON : we have to handle the zeroes on the edges separately because as we make the rows zero all cells will become zero

class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> Zeroes(m,0);
        bool firstRowHasZero = false;
        bool firstColHasZero = false;

        for (int i = 0; i < n; ++i)
        {
            if (matrix[i][0] == 0)
            {
                firstColHasZero = true;
                break;
            }
        }

        for (int j = 0; j < m; ++j)
        {
            if (matrix[0][j] == 0)
            {
                firstRowHasZero = true;
                break;
            }
        }

        for (int i = 1; i < n; ++i)
        {
            for (int j = 1; j < m; ++j)
            {
                if (matrix[i][j] == 0)
                {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        for (int i = 1; i < n; ++i)
        {
            if (matrix[i][0] == 0)
            {
                for (int j = 1; j < m; ++j)
                {
                    matrix[i]= Zeroes;
                }
            }
        }

        for (int j = 1; j < m; ++j)
        {
            if (matrix[0][j] == 0)
            {
                for (int i = 1; i < n; ++i)
                {
                    matrix[i][j] = 0;
                }
            }
        }

        if (firstRowHasZero)
        {
            for (int j = 0; j < m; ++j)
            {
                matrix[0] = Zeroes;
            }
        }

        if (firstColHasZero)
        {
            for (int i = 0; i < n; ++i)
            {
                matrix[i][0] = 0;
            }
        }
    }

    void printMatrix(const vector<vector<int>> &matrix)
    {
        for (const auto &row : matrix)
        {
            for (const auto &elem : row)
            {
                cout << elem << ' ';
            }
            cout << endl;
        }
    }
};
int main()
{

    vector<vector<int>> matrix = {{0, 1, 2, 0},
                                  {3, 4, 5, 2},
                                  {1, 3, 4, 5}};

    Solution s1;
    s1.setZeroes(matrix);
    s1.printMatrix(matrix);
    return 0;
}
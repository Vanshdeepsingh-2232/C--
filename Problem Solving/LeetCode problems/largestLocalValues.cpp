#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Input: grid = [[9,9,8,1],[5,6,2,6],[8,2,6,4],[6,2,2,2]]
// Output: [[9,9],[8,6]]

// Explanation: The diagram above shows the original matrix and the generated matrix.
// Notice that each value in the generated matrix corresponds to the largest value of a contiguous 3 x 3 matrix in grid.v




class Solution
{
public:

    int maxMatrix(int &i,int &j){
        int max=0;
        vector<int> points={};
    }

    int validNumber(vector<vector<int>> &grid){
        int max=0;
        for(int i=0;i<grid.size();i++){
            
        }




    }


    vector<vector<int>> largestLocal(vector<vector<int>> &grid)
    {
        int n = grid.size();
        vector<vector<int>> ansMatrix((n - 2), vector<int>((n - 2), 0));
        for (int i = 0; i < ansMatrix.size(); i++)
        {
            for (int j = 0; j < ansMatrix[i].size(); j++)
            {
                ansMatrix[i][j]=validNumber(grid);
            }
            cout << endl;
        }
        return ansMatrix;
    }
};

int main()
{
    vector<vector<int>> matrix = {{9, 9, 8, 1},
                                  {5, 6, 2, 6},
                                  {8, 2, 6, 4},
                                  {6, 2, 2, 2}};

    Solution s1;
    vector<vector<int>> v = s1.largestLocal(matrix);
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v[i].size(); j++)
        {
            cout << v[i][j];
        }
        cout << endl;
    }

    return 0;
}
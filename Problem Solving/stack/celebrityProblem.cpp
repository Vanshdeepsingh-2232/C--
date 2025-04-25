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
    int celebrity(vector<vector<int>> &mat)
    {
        int n = mat.size();
        int top = 0;
        int down = n - 1;
        while (top < down)
        {
            if (mat[top][down] == 1)
                top++;
            else if (mat[down][top] == 1)
                down--;
            else
            {
                top++;
                down--;
            }
        }
        if (top > down)
            return -1;

        return top;
    }
};

int main()
{

    vector<vector<int>> matrix = {{1, 1, 0}, {0, 1, 0}, {0, 1, 1}};

    Solution s1;
    cout << s1.celebrity(matrix);

    return 0;
}
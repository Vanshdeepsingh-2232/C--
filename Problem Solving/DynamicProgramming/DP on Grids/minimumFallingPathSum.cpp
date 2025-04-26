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
    int minFallingPathSum(vector<vector<int>> &matrix)
    {


    }
};

int main()
{
    vector<vector<int>> v = {{2, 1, 3},
                             {6, 5, 4},
                             {7, 8, 9}};

    Solution s1;
    cout<<s1.minFallingPathSum(v);
    return 0;
}
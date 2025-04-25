#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution
{

private:
    void findPaths(vector<vector<int>> &mat, int i, int j, string Path, vector<string> &ans)
    {

        if (i == mat.size() - 1 && j == mat[i].size() - 1)
        {
            ans.push_back(Path);
            return;
        }
        mat[i][j] = -1;

        if (i - 1 >= 0 && mat[i - 1][j] == 1)
            findPaths(mat, i - 1, j, Path + 'U', ans);
        if (j + 1 < mat[i].size() && mat[i][j + 1] == 1)
            findPaths(mat, i, j + 1, Path + 'R', ans);
        if (i + 1 < mat.size() && mat[i + 1][j] == 1)
            findPaths(mat, i + 1, j, Path + 'D', ans);
        if (j - 1 >= 0 && mat[i][j - 1] == 1)
            findPaths(mat, i, j - 1, Path + 'L', ans);

        mat[i][j] = 1;
    }

public:
    vector<string> findPath(vector<vector<int>> &mat)
    {
        vector<string> ans;
        string Path = "";
        findPaths(mat, 0, 0, Path, ans);
        return ans;
    }
};

int main()
{

    vector<vector<int>> mat = {{1, 0, 0, 0},
                               {1, 1, 0, 1},
                               {1, 1, 0, 0},
                               {0, 1, 1, 1}};
    Solution s1;
    s1.findPath(mat);
    return 0;
}

// #include <iostream>
// #include <vector>
// #include <string>
// using namespace std;

// class Solution
// {
// private:
//     void findPaths(vector<vector<int>> &mat, int i, int j, string Path, vector<string> &ans)
//     {
//         int n = mat.size();
//         int m = mat[0].size();

//         // If reached bottom-right corner, add path to answer
//         if (i == n - 1 && j == m - 1)
//         {
//             ans.push_back(Path);
//             return;
//         }

//         // Mark the cell as visited
//         mat[i][j] = -1;

//         // Move Up
//         if (i - 1 >= 0 && mat[i - 1][j] == 1)
//         {
//             findPaths(mat, i - 1, j, Path + 'U', ans);
//         }
//         // Move Right
//         if (j + 1 < m && mat[i][j + 1] == 1)
//         {
//             findPaths(mat, i, j + 1, Path + 'R', ans);
//         }
//         // Move Down
//         if (i + 1 < n && mat[i + 1][j] == 1)
//         {
//             findPaths(mat, i + 1, j, Path + 'D', ans);
//         }
//         // Move Left
//         if (j - 1 >= 0 && mat[i][j - 1] == 1)
//         {
//             findPaths(mat, i, j - 1, Path + 'L', ans);
//         }

//         // Unmark the cell to allow other paths to pass through
//         mat[i][j] = 1;
//     }

// public:
//     vector<string> findPath(vector<vector<int>> &mat)
//     {
//         vector<string> ans;
//         if (mat.empty() || mat[0][0] == 0 || mat[mat.size() - 1][mat[0].size() - 1] == 0)
//             return ans;

//         string Path = "";
//         findPaths(mat, 0, 0, Path, ans);

//         // Print paths
//         cout << "Number of paths: " << ans.size() << endl;
//         for (const string &path : ans)
//         {
//             cout << path << endl;
//         }

//         return ans;
//     }
// };

// int main()
// {
//     vector<vector<int>> mat = {{1, 0, 0, 0},
//                                {1, 1, 0, 1},
//                                {1, 1, 0, 0},
//                                {0, 1, 1, 1}};
//     Solution s1;
//     s1.findPath(mat);

//     return 0;
// }

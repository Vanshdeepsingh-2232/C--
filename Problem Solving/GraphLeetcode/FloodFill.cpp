#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <set>
using namespace std;

class Solution
{
public:
    bool inBounds(int n, int m, int i, int j)
    {
        if (i > n - 1 || j > m - 1)
            return false;
        if (i < 0 || j < 0)
            return false;
        return true;
    }
    void flood(vector<vector<int>> &image, int i, int j, int color, vector<pair<int, int>> &directions, int &intial, int &n, int &m)
    {

        if (image[i][j] == intial)
            image[i][j] = color;
        for (pair<int, int> &d : directions)
        {
            if (inBounds(n, m, i + d.first, j + d.second) && image[i + d.first][j + d.second] == intial)
                flood(image, i + d.first, j + d.second, color, directions, intial, n, m);
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
    {
        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int intial = image[sr][sc];
        int n = image.size();
        int m = image[0].size();
        flood(image, sr, sc, color, directions, intial, n, m);
        return image;
    }
};

int main()
{

    vector<vector<int>> image = {{1, 1, 1},
                                 {1, 1, 0},
                                 {1, 0, 1}};

    int sr = 1, sc = 1, color = 2;

    Solution s1;
    vector<vector<int>> g = s1.floodFill(image, sr, sc, color);
    for (auto i : g)
    {
        for (auto j : i)
            cout << j;
        cout << endl;
    }

    return 0;
}
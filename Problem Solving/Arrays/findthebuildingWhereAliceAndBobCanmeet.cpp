#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <set>
using namespace std;

// nice solution but TLE at 945/952

//  class Solution
//  {
//  public:
//      int findBuilding(int a, int b, const vector<int> &heights)
//      {
//          if (a > b)
//              swap(a, b);
//          if (heights[b] > heights[a])
//              return b;
//          while (b < heights.size() && heights[b] <= heights[a])
//              b++;
//          return (b < heights.size() && heights[b] > heights[a]) ? b : -1;
//      }
//      vector<int> leftmostBuildingQueries(vector<int> &heights, vector<vector<int>> &queries)
//      {
//          vector<int> ans;
//          for (int i = 0; i < queries.size(); i++)
//          {
//              if (queries[i][0] == queries[i][1])
//                  ans.push_back(queries[i][0]);
//              else
//                  ans.push_back(findBuilding(queries[i][0], queries[i][1], heights));
//          }
//          return ans;
//      }
//  };

class Solution
{
public:
    vector<int> leftmostBuildingQueries(vector<int> &heights, vector<vector<int>> &queries)
    {
        vector<int> ans;

        return ans;
    }
};

int main()
{
    vector<int> heights = {5, 3, 8, 2, 6, 1, 4, 6};
    // vector<int> heights = {6, 4, 8, 5, 2, 7};
    vector<vector<int>> queries = {{0, 7}, {3, 5}, {5, 2}, {3, 0}, {1, 6}};
    // vector<vector<int>> queries = {{0, 1}, {0, 3}, {2, 4}, {3, 4}, {2, 2}};
    Solution s1;
    vector<int> ans = s1.leftmostBuildingQueries(heights, queries);
    for (int &i : ans)
        cout << i << "_";
    return 0;
}
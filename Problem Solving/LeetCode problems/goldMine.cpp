#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// Example 1:

// Input: grid = {{0,6,0},{5,8,7},{0,9,0}}
// Output: 24
// Explanation:
// {{0,6,0},
//  {5,8,7},
//  {0,9,0}}
// Path to get the maximum gold, 9 -> 8 -> 7.


// Example 2:

// Input: grid = {{1,0,7},{2,0,6},{3,4,5},{0,3,0},{9,0,20}}
// Output: 28
// Explanation:
// {{1,0,7},
//  {2,0,6},
//  {3,4,5},
//  {0,3,0},
//  {9,0,20}}
// Path to get the maximum gold, 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7.
class Solution {
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        for (int i = 0; i < grid.size(); i++)
        {
          for (int i = 0; i < grid[i].size(); i++)
          {
            
          }
          
        }
        
    }
};
int main(){
    vector<vector<int>> v={{0,6,0},{5,8,7},{0,9,0}};
    
  return 0;
}
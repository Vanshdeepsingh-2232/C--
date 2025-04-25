// #include <iostream>
// #include <vector>
// #include <algorithm>
// #include <set>
// #include <unordered_map>
// #include <queue>
// #include <sstream>
// using namespace std;

// class Solution
// {

// private:
//     unordered_map<int, vector<int>> setlist;
//     queue<int> Q;

//     void printComponents()
//     {
//         for (const auto &entry : setlist)
//         {
//             cout << "Key " << entry.first << ": ";
//             for (const auto &value : entry.second)
//             {
//                 cout << value << " ";
//             }
//             cout << endl;
//         }
//     }
//     void printVectorOfSets(const vector<set<int>> &answer)
//     {
//         for (size_t i = 0; i < answer.size(); ++i)
//         {
//             cout << "Set " << i << ": { ";
//             for (const int &num : answer[i])
//             {
//                 cout << num << " ";
//             }
//             cout << "}" << endl;
//         }
//     }
//     int countSegments(const vector<char> &chars)
//     {
//         // Construct the string from the given characters
//         string s;
//         for (char c : chars)
//         {
//             s += c;
//         }



//         // Split the string based on '0' and count non-empty segments
//         vector<string> segments;
//         stringstream ss(s);
//         string segment;

//         while (getline(ss, segment, '0'))
//         {
//             if (!segment.empty())
//             {
//                 segments.push_back(segment);
//             }
//         }

    

//         // Return the number of non-empty segments
//         return segments.size();
//     }

// public:
//     int countEmptySets(const vector<set<int>> &sets)
//     {
//         int emptyCount = 0;
//         for (const auto &s : sets)
//         {
//             if (s.empty())
//             {
//                 emptyCount++;
//             }
//         }
//         return emptyCount;
//     }
//     void bfs(int i, vector<bool> &traversed, set<int> &answer)
//     {
//         if (traversed[i])
//             return;
//         traversed[i] = true;
//         Q.push(i);

//         while (!Q.empty())
//         {
//             int top = Q.front();
//             answer.insert(top);
//             Q.pop();

//             for (auto &neighbours : setlist[top])
//             {
//                 if (!traversed[neighbours])
//                 {
//                     traversed[neighbours] = true;
//                     Q.push(neighbours);
//                 }
//             }
//         }
//     }
//     int find_number_of_connected_components(int &n, int &m)
//     {

//         vector<bool> traversed(max(n, m), false);
//         vector<set<int>> answer(max(n, m));
//         int comp = 0;
//         printComponents();
//         vector<int> keys;
//         for (const auto &entry : setlist)
//         {
//             int key = entry.first;
//             keys.push_back(key);
//         }

//         for (int i = 0; i < keys.size(); i++)
//         {
//             bfs(keys[i], traversed, answer[comp++]);
//         }

//         printVectorOfSets(answer);

//         int empt_count = countEmptySets(answer);
//         int ans = (max(n, m) - empt_count);
//         return ans;
//     }
//     int numIslands(vector<vector<char>> &grid)
//     {
//         int n = grid.size();
//         int m = grid[0].size();

//         if (n == 1)
//         {
//             int segmentCount = countSegments(grid[0]);
//             return segmentCount;
//         }

//         for (int i = 0; i < n; i++)
//         {
//             for (int j = 0; j < m; j++)
//             {
//                 if (grid[i][j] == '1')
//                 {
//                     setlist[i].push_back(j);
//                 }
//                 else
//                     continue;
//             }
//         }
//         printComponents();
//         int ans = find_number_of_connected_components(n, m);
//         return ans;
//     }
// };

// int main()
// {    // vector<vector<char>> grid = {{'1', '1', '1', '1', '0'},
//     //                              {'1', '1', '0', '1', '0'},
//     //                              {'1', '1', '0', '0', '0'},
//     //                              {'0', '0', '0', '0', '0'}};


//     vector<vector<char>> grid={{'1', '0', '1', '1', '0', '1', '1'}};
//     Solution s1;
//     cout<<s1.numIslands(grid);

//     return 0;
// }













//OPTIMAL APPROACH

#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;
class Solution {
private:     
    int dirs[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    void exploreIsland(vector<vector<char>>&grid, int r, int c){
        grid[r][c] = '0';
        for(auto &dir : dirs){
            int newR = r + dir[0], newC = c + dir[1];
            if(isSafe(newR, newC, grid)){
              exploreIsland(grid, newR, newC);
            }
        }
    }
    bool isSafe(int newR, int newC,vector<vector<char>>&grid){
        if(newR == grid.size() || newC == grid[0].size() || newR < 0 || newC < 0 || grid[newR][newC] == '0')return false;
        return true;
    }    
public:
    int numIslands(vector<vector<char>>& grid) {
        int islandCnt = 0;
        for(int r = 0; r<grid.size(); r++){
            for(int c = 0; c < grid[0].size(); c++){
                if(grid[r][c] == '1'){
                    exploreIsland(grid, r, c);
                    islandCnt++;
                }
            }
        }
        return islandCnt;
    }
};


int main(){
  return 0;
}
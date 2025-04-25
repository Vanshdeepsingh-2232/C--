#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
using namespace std;

// class Solution
// {

// public:
//     void printBoard(const vector<vector<char>> &board)
//     {
//         for (const auto &row : board)
//         {
//             for (const auto &ch : row)
//             {
//                 cout << ch << ' ';
//             }
//             cout << endl;
//         }
//     }

//     vector<pair<int, int>> get_neihbours(pair<int, int> &c, vector<vector<char>> &board, vector<vector<bool>> &traversed)
//     {
//         int i = c.first;
//         int j = c.second;

//         int n = board.size();
//         int m = board[0].size();
//         vector<pair<int, int>> neighbours;

//         // Up
//         if (i - 1 >= 0 && !traversed[i - 1][j])
//         {
//             neighbours.push_back({i - 1, j});
//         }
//         // Down
//         if (i + 1 < n && !traversed[i + 1][j])
//         {
//             neighbours.push_back({i + 1, j});
//         }
//         // Left
//         if (j - 1 >= 0 && !traversed[i][j - 1])
//         {
//             neighbours.push_back({i, j - 1});
//         }
//         // Right
//         if (j + 1 < m && !traversed[i][j + 1])
//         {
//             neighbours.push_back({i, j + 1});
//         }

//         return neighbours;
//     }

//     void solve(vector<vector<char>> &board)
//     {
//         int n = board.size();
//         int m = board[0].size();
//         vector<vector<bool>> traversed(board.size(), vector<bool>(board[0].size(), false));
//         queue<pair<int, int>> Q;
//         pair<int, int> source ={0, 0};
//         Q.push(source);

//         vector<vector<char>> layers(n, vector<char>(m, ' '));
//         int i = 0;
//         while (!Q.empty())
//         {
//             auto top = Q.front();
//             Q.pop();
//             layers[i++].push_back(board[top.first][top.second]);
//             traversed[top.first][top.second] = true;
//             vector<pair<int, int>> neihbours = get_neihbours(top, board, traversed);

//             for (auto neihbour : neihbours)
//             {
//                 Q.push(neihbour);
//             }
//         }

//         printBoard(layers);
//     }
// };

// Input: board = {
//   {'X','X','X','X'},
//   {'X','O','O','X'},
//   {'X','O','O','X'},
//   {'X','X','X','O'}
// }

// Output: {
//   {'X','X','X','X'},
//   {'X','X','X','X'},
//   {'X','X','X','X'},
//   {'X','X','X','O'}
// }
// class Solution {
// public:
//     // Function to print a vector<vector<char>> (the board)
//     void printBoard(const vector<vector<char>>& board) {
//         for (const auto& row : board) {
//             for (const auto& ch : row) {
//                 cout << ch << ' ';
//             }
//             cout << endl;
//         }
//     }

//     // Function to get valid neighbors for a given cell
//     vector<pair<int, int>> getNeighbours(pair<int, int> c, vector<vector<char>>& board, vector<vector<bool>>& traversed) {
//         int i = c.first;
//         int j = c.second;

//         int n = board.size();
//         int m = board[0].size();

//         vector<pair<int, int>> neighbours;

//         // Up
//         if (i - 1 >= 0 && !traversed[i - 1][j]) {
//             neighbours.push_back({i - 1, j});
//         }
//         // Down
//         if (i + 1 < n && !traversed[i + 1][j]) {
//             neighbours.push_back({i + 1, j});
//         }
//         // Left
//         if (j - 1 >= 0 && !traversed[i][j - 1]) {
//             neighbours.push_back({i, j - 1});
//         }
//         // Right
//         if (j + 1 < m && !traversed[i][j + 1]) {
//             neighbours.push_back({i, j + 1});
//         }

//         return neighbours;
//     }

//     // Function to solve the board problem and collect layers of characters
//     void solve(vector<vector<char>>& board) {
//         int n = board.size();
//         int m = board[0].size();
//         vector<vector<bool>> traversed(n, vector<bool>(m, false));
//         queue<pair<int, int>> Q;

//         // Start BFS from the top-left corner of the board
//         pair<int, int> source = {0, 0};
//         Q.push(source);
//         traversed[source.first][source.second] = true;

//         // This will store characters from the board in BFS layer order
//         vector<vector<char>> layers(n, vector<char>(m, ' '));

//         // BFS traversal
//         int layer_index = 0;
//         while (!Q.empty()) {
//             int q_size = Q.size();  // Number of elements at the current layer

//             for (int k = 0; k < q_size; ++k) {
//                 auto top = Q.front();
//                 Q.pop();
//                 int i = top.first;
//                 int j = top.second;

//                 // Collect the character at the current layer index

//                 // Get all valid untraversed neighbors
//                 vector<pair<int, int>> neighbours = getNeighbours(top, board, traversed);
//                 for (const auto& neighbour : neighbours) {
//                     int ni = neighbour.first;
//                     int nj = neighbour.second;

//                     // Mark as traversed and add to the queue
//                     traversed[ni][nj] = true;
//                     layers[i++].push_back(board[ni][nj]);
//                     Q.push({ni, nj});
//                 }
//             }
//             ++layer_index;
//         }

//         // Print the collected layers
//         printBoard(layers);
//     }
// };
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------

class Solution
{
public:
    bool inBounds(int n, int m, int i, int j) { return !(i < 0 || j < 0 || i >= n || j >= m); }

    void dfs(int i, int j, vector<vector<char>> &board, vector<pair<int, int>> &directions, int n, int m)
    {
        if (board[i][j] == 'y')
            return;

        board[i][j] = 'y';
        for (auto &d : directions)
        {
            int ni = i + d.first, nj = j + d.second;
            if (inBounds(n, m, ni, nj) && board[ni][nj] == 'O')
                dfs(ni, nj, board, directions, n, m);
        }
    }

    void solve(vector<vector<char>> &board)
    {
        if (board.empty())
            return;
        int n = board.size();
        int m = board[0].size();
        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        for (int i = 0; i < n; i++)
        {
            if (board[i][0] == 'O')
                dfs(i, 0, board, directions, n, m);
            if (board[i][m - 1] == 'O')
                dfs(i, m - 1, board, directions, n, m);
        }
        for (int j = 0; j < m; j++)
        {
            if (board[0][j] == 'O')
                dfs(0, j, board, directions, n, m);
            if (board[n - 1][j] == 'O')
                dfs(n - 1, j, board, directions, n, m);
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (board[i][j] == 'O')
                    board[i][j] = 'X';
                else if (board[i][j] == 'y')
                    board[i][j] = 'O';
            }
        }
    }
};
int main()
{

    vector<vector<char>> board =
        {
            {'X', 'O', 'X'},
            {'O', 'X', 'O'},
            {'X', 'O', 'X'}};
    // {{"X","O","X"},
    //  {"O","X","O"},
    //  {"X","O","X"}}

    // [["X","O","X"],
    //  ["X","X","X"],
    //  ["X","O","X"]]

    // [["X","O","X"],
    //  ["O","X","O"],
    //  ["X","O","X"]]
    Solution s1;
    s1.solve(board);
    return 0;
}
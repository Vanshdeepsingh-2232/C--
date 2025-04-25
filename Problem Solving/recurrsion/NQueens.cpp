#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution
{

private:
    void solve(int col, vector<string> &board, vector<vector<string>> &ans, vector<bool> &rowHash, vector<bool> &positiveDiagonalHash, vector<bool> &negativeDiagonalHash, int n)
    {
        if (col == n)
        {
            ans.push_back(board);
            return;
        }

        for (int i = 0; i < n; i++)
        {
            if (rowHash[i] == 0 && positiveDiagonalHash[i + col] == 0 && negativeDiagonalHash[n - 1 + col - i] == 0)
            {
                board[i][col] = 'Q';
                rowHash[i] = 1;
                positiveDiagonalHash[i + col] = 1;
                negativeDiagonalHash[n - 1 + col - i] = 1;
                solve(col + 1, board, ans, rowHash, positiveDiagonalHash, negativeDiagonalHash, n);
                board[i][col] = '.';
                rowHash[i] = 0;
                positiveDiagonalHash[i + col] = 0;
                negativeDiagonalHash[n - 1 + col - i] = 0;
            }
        }
    }

public:
    vector<vector<string>> solveNQueens(int n)
    {
        vector<vector<string>> result;
        vector<string> S_board(n);
        string s(n, '.');
        for (int i = 0; i < n; i++)
            S_board[i] = s;
        vector<bool> rowHash(n, 0);
        vector<bool> positiveDiagonalHash(2 * n - 1, 0);
        vector<bool> negativeDiagonalHash(2 * n - 1, 0);
        int col = 0;
        solve(col, S_board, result, rowHash, positiveDiagonalHash, negativeDiagonalHash, n);
        return result;
    }
};

int main()
{

    int input = 2;
    Solution s1;
    vector<vector<string>> v = s1.solveNQueens(input);
    cout << v.size();
    
    return 0;
}

//1-1
//2-0
//3-0
//4-2
//5-10
//6-4
//7-40
//8-92
//9-352
//10-724
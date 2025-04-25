#include <iostream>
#include <vector>
#include <utility>

using namespace std;

class Solution {
    vector<pair<int,int>> locations;
    const int WordCount = 1;

public:
    void findWord(vector<vector<char>>& board, string &word) {
        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board[i].size(); j++) {
                if(board[i][j] == word[0]) {
                    locations.push_back(make_pair(i, j));
                }
            }
        }
    }

    bool dfs(int x, int y, vector<vector<char>>& board, string &word, int WordCount) {
        if (WordCount == word.size())
            return true;

        char temp = board[x][y];
        cout<<temp<<"----Reached---"<<endl;
        board[x][y] = '.'; // Mark as visited

        bool found = false;

        if (y + 1 < board[x].size() && board[x][y + 1] == word[WordCount])
            found = dfs(x, y + 1, board, word, WordCount + 1);
        
        
        else if (x - 1 >= 0 && board[x - 1][y] == word[WordCount])
            found = dfs(x - 1, y, board, word, WordCount + 1);
        
        
        else if (y - 1 >= 0 && board[x][y - 1] == word[WordCount])
            found = dfs(x, y - 1, board, word, WordCount + 1);
        
        
        else if (x + 1 < board.size() && board[x + 1][y] == word[WordCount])
            found = dfs(x + 1, y, board, word, WordCount + 1);

        
        
        board[x][y] = temp; // Restore the original character
        return found;
    }

    bool exist(vector<vector<char>>& board, string &word) {
        findWord(board, word);
        
        for(int i = 0; i < locations.size(); i++) {
            const int x = locations[i].first;
            const int y = locations[i].second;
            
            if (dfs(x, y, board, word, WordCount))
                return true;
        }

        return false;
    }
};

int main() {
    Solution s1;
    string word = "ABCCED";
    vector<vector<char>> v = {
        {'A', 'B', 'C', 'E'},
        {'S', 'F', 'C', 'S'},
        {'A', 'D', 'E', 'E'}
    };
    cout << (s1.exist(v, word) ? "true" : "false") << endl;

    return 0;
}

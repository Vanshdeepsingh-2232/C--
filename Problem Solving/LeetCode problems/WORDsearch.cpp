#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;




class Solution {
public:
    bool dfs(int i , int j , int n , int m , vector<vector<char>> &board , string &word , int k){
        if(k==word.size()) return true;
        if(i<0 || j<0 || i==n || j==m || board[i][j] != word[k]) return false;
        char ch = board[i][j];
        board[i][j]='.';
        bool a=dfs(i+1, j , n,m,board,word,k+1);
        bool b=dfs(i, j+1 , n,m,board,word,k+1);
        bool c=dfs(i-1, j , n,m,board,word,k+1);
        bool d=dfs(i, j-1 , n,m,board,word,k+1);

        board[i][j]=ch;
        return a || b || c || d;

    }

    bool exist(vector<vector<char>> &board , string &word){
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[i].size();j++){
                if(board[i][j] == word[0]){
                    if(dfs(i,j,board.size(),board[i].size(),board,word,0)) return true;
                }
            }
        }
        return false;
    }


};


// Input: board = {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}}, word = 'ABCED'
// Output: true

int main(){
    Solution s1;
    string word="ABCCED";
    vector<vector<char>> v={{'A','B','C','E'},
                            {'S','F','C','S'},
                            {'A','D','E','E'}};
    cout<<s1.exist(v,word);


  return 0;
}
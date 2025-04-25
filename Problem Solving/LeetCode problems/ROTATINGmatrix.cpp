#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


class Solution {

public:
    
    void transpose(vector<vector<int>>& matrix){
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<i;j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }
    }
    void reverse(vector<int> &v){
        for(int i=0,j=v.size()-1 ; i<j ; i++,j--){
            swap(v[i],v[j]);
        }
    }

    void rotate(vector<vector<int>>& matrix) {
        transpose(matrix);

        for(int i=0;i<matrix.size();i++){
            reverse(matrix[i]);
        }

    }
};


// Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
// Output: [[7,4,1],[8,5,2],[9,6,3]]



int main(){
    Solution s1;
    vector<vector<int>> v={{1,2,3},
                           {4,5,6},
                           {7,8,9}};
    s1.rotate(v);
   
    for(int i=0;i<v.size();i++){
        for(int j=0;j<v[i].size();j++){
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }


  return 0;
}
#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;

int formingMagicSquare(vector<vector<int>> s) {
    int possible_squares[8][3][3]{
        {{4,3,8},
         {9,5,1},
         {2,7,6}},
         
         {{8,3,4},
         {1,5,9},
         {6,7,2}},
         
         {{8,1,6},
         {3,5,7},
         {4,9,2}},
         
         {{4,9,2},
         {3,5,7},
         {8,1,6}},
         
         {{2,7,6},
         {9,5,1},
         {4,3,8}},
         
         {{6,7,2},
         {1,5,9},
         {8,3,4}},
         
         {{6,1,8},
         {7,5,3},
         {2,9,4}},
         
         {{2,9,4},
         {7,5,3},
         {6,1,8}},
    };
    int cost=100;
    for(int i=0;i<8;i++){
        int c=0;
        for(int j=0;j<3;j++){
            for(int k=0;k<3;k++){
                c+=abs(s[j][k]-possible_squares[i][j][k]);
            }
        }
        cost=min(cost,c);
    }
    return cost;
}

int main(){
  return 0;
}
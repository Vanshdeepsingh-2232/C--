#include<iostream>
#include<vector>
using namespace std;

/*
vector<vector<int>> pascaltri(int n){
    vector<vector<int>> Ptriangle(n);
    for(int i=0;i<n;i++){
        Ptriangle[i].resize(i+1);
        for(int j=0;j<i+1;j++){
            if(j==0 || j==i){
                Ptriangle[i][j]=1;
            }
            else{
                Ptriangle[i][j]=Ptriangle[i-1][j]+Ptriangle[i-1][j-1];
            }
        }
    }
    return Ptriangle;
}*/


class Solution {
public:
    vector<vector<int>> generate(int numRows) {
         vector<vector<int>> Ptriangle(numRows);
         if(numRows==0){
             return Ptriangle;
         }
         if(numRows==1){
             Ptriangle[0].push_back(1);
             return Ptriangle;
         }
        for(int i=0;i<numRows;i++){
            Ptriangle[i].resize(i+1);
            for(int j=0;j<i+1;j++){
                if(j==0 || j==i){
                    Ptriangle[i][j]=1;
                }
                else{
                    Ptriangle[i][j]=Ptriangle[i-1][j]+Ptriangle[i-1][j-1];
                }
            }
        }
        return Ptriangle;
    }
};
int main(){
    Solution s1;
    int numRows=1;
    vector <vector <int>>  ans;
    ans=s1.generate(numRows);
    for (int i = 0; i < ans.size(); i++){
        for(int j=i;j<=numRows;j++){
            cout<<"  ";
        }
        for(int j=0;j < ans[i].size();j++){
            cout<<"  "<<ans[i][j]<<"  ";
        }
        cout<<endl;
    }
  return 0;
}




























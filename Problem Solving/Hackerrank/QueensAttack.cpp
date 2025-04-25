#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;

pair<int,int> sub(pair<int,int> a,pair<int,int> b){
    cout<<a.first-b.first<<"-"<<a.second-b.second<<endl;
    return {a.first-b.first,a.second-b.second};
}


int queensAttack(int n, int k, int r_q, int c_q, vector<vector<int>> obstacles) {
    return 0;
}

int main(){

    //sub({4,3},{4,2});
    int a=10;
    int b=13;

    int c=15;
    c^=a;
    cout<<c;

  return 0;
}
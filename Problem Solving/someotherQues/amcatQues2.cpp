//server question

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int processcount(vector<int> p){
    int result=0;
    for(int i=0;i<p.size();i++){
        if(i==0 || i%2==0){
            result+=p[i];
        }
    }
    return  result;
}

int main(){
    vector<int> processes={2,-3,8,-6,-7,18,1};
    cout<<processcount(processes);
  return 0;
}
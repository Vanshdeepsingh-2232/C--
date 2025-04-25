#include<iostream>
using namespace std;

int main(){
    int n=1;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            cout<<" ";
        }
        for(int j=0;j<i;j++){
            cout<<" "<<i+j<<" ";
        }
        cout<<endl;
    }
  return 0;
}
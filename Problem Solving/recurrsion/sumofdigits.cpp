#include<iostream>
using namespace std;

int f(int n){
    int sum=0;
    if(n%10 == n){
        return n;
    }
    return f(n/10)+n%10;
}


int main(){
    int a=1234;
    cout<<f(a);
  return 0;
}
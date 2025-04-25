#include<iostream>
using namespace std;

int sumA(int a,int b){
    return a+b;
}

int sumB(int a , int b ,int c ){
    return a+b+c;
}


int main(){
    cout<<sumA(1,2)<<endl;
    cout<<sumB(1,2,3)<<endl;
  return 0;
}
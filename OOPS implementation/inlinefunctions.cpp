#include<iostream>
using namespace std;

inline int product(int a ,int b){
    return a*b;
}

int main(){
    cout<<product(5,5);
    return 0;
}
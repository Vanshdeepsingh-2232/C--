#include<iostream>
using namespace std;

class B;

class A{
    int x=10;
    friend void sum(A,B);
};

class B{
    int y=10;
    friend void sum(A,B);
};

void sum(A a1,B b1){
    cout<<a1.x+b1.y;
}


int main(){
    A a1;
    B b1;
    sum( a1, b1);
  return 0;
}
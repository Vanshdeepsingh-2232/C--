#include<iostream>
using namespace std;

class A{
    public:
    A(){
        cout<<"Class A";
    }
};
class B{
    public:
    B(){
        cout<<"Class B";
    }
};
class C:public A,virtual public B{};

int main(){
    C c1;

  return 0;
}
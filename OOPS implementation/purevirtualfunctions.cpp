#include<iostream>
using namespace std;


//abstract class
class A{
    public:
    virtual void prints()=0;
    virtual ~A(){
        cout<<"Destructor called A."<<endl;
    }
};
class B:public A{
    public:
    void prints(){
        cout<<"Using pure virtual function."<<endl;
    }
     ~B(){
        cout<<"Destructor called B."<<endl;
    }
};

int main(){
    A* a1=new B();
    delete a1;
  return 0;
}
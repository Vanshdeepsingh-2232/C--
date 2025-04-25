#include<iostream>
using namespace std;
class A{
    public:
    void prints(){
        cout<<"this is class a"<<endl;
    }
};
class B:public virtual A{};
class C:public virtual A{};
class D:public B,C{};
int main(){
    D d1;
    d1.prints();
  return 0;
}
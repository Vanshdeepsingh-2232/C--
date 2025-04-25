#include<iostream>
#include<list>
using namespace std;

class User{
    public:
    virtual void prints(){
        cout<<"This is the user"<<endl;
    }
};
class SuperUser:public User{
    public:
    void prints(){
        cout<<"this is the Super user"<<endl;
    }
};
int main(){
    User* Uptr;
    User u;
    SuperUser s;
    Uptr=&u;
    Uptr->prints();
    Uptr=&s;
    Uptr->prints();
  return 0;
}
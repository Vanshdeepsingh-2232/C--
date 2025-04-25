#include<iostream>
using namespace std;

class Abc{
    int x,y,z;
    public:
    //Default Constructor
    Abc(){ }

    //Parameterized Constructors
    Abc(int a ,int b){
        x=a;y=b;
    }
    //Copy Constructor
    Abc(Abc &a){
        x=a.x;y=a.y;
    }

    void show(){
        cout<<"X ="<<x<<endl;
        cout<<"Y ="<<y<<endl;
    }

    ~Abc(){
        cout<<"Destructor called"<<endl;
    }

};


int main(){
    Abc a1;
    a1.show();
    Abc a2(1,2);
    a2.show();
    Abc a3=a2;
    a3.show();
  return 0;
}
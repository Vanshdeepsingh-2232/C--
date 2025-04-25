
//USED IN USING THE GLOBAL VARIABLE SAME  NAME OF LOCAL VARIABLE

// #include<iostream>
// using namespace std;

// int n=5;//global variable

// int main(){
//     int n=10;

//     cout<<n<<"  Local variable"<<endl;
//     cout<<::n<<"  Global variable"<<endl;


//   return 0;
// }


//USED IN DECLARING EXTERNAL FUNCTIONS AND EXTERNAL CONSTRUCTORS

// #include<iostream>
// using namespace std;

// class A
// {
// public:
//     void fun();
// };

// void A::fun(){
//     cout<<"FUN"<<endl;
// }


// int main(){
//     A a1;
//     a1.fun();
//   return 0;
// }

//USED IN MULTIPLE INHERITENCE

#include<iostream>
using namespace std;

class A{
    public:
    int a=10;
  
};
class B{
    public:
    int a=20;
};

class C: public A,public B{
    public:
    void show(){
        cout<<A::a<<"A"<<endl;
        cout<<B::a<<"B"<<endl;
    }
};


int main(){
    C c1;
    c1.show();
  return 0;
}
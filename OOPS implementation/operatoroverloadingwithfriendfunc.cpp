// #include<iostream>
// using namespace std;

// class Complex{
//   int real,img;
//   public:
//   Complex(){}
//   Complex(int a, int b){
//     real=a;img=b;
//   }
//   void show(){
//     cout<<real<<" + "<<img<<"i"<<endl;
//   }

//   //Operator overloading using friend function
//   friend Complex operator+(Complex& obj1,Complex& obj2);

// };
// Complex operator+(Complex& obj1,Complex& obj2){
//     Complex temp;
//     temp.real=obj1.real+obj2.real;
//     temp.img=obj1.img+obj2.img;
//     return temp;
// }

// int main(){
//   Complex c1(2,3);
//   Complex c2(4,5);
//   Complex c3=c1+c2;

//   c3.show();
//   return 0;
// }









//overloading of insertion operrator

#include<iostream>
using namespace std;

class Complex{
  int real,img;
  public:
  Complex(){}
  Complex(int a, int b){
    real=a;img=b;
  }
  //Operator overloading using friend function
  friend ostream& operator << (ostream& COUT,Complex& c1);

};

ostream& operator<<(ostream& COUT,Complex& c1){
    COUT<<"Real ="<<c1.real<<"IMG ="<<c1.img<<endl;
}

int main(){
    Complex c1(1,2);
    cout<<c1;
  return 0;
}
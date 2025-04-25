#include<iostream>
using namespace std;

class Complex{
  int real,img;
  public:
  Complex(){}
  Complex(int a, int b){
    real=a;img=b;
  }
  void show(){
    cout<<real<<" + "<<img<<"i"<<endl;
  }

  //operator overloading
  Complex operator+(Complex obj){
    Complex temp;
    temp.real=real+obj.real;
    temp.img=img+obj.img;
    return temp;
  }
};

int main(){
  Complex c1(2,3);
  Complex c2(4,5);
  Complex c3=c1+c2;
  c3.show();
  return 0;
}
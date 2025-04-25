#include<iostream>
using namespace std;

class Abc{
    int x,y;
    public:
    Abc(int x,int y){
        this->x=x;
        this->y=y;
    }
};

int main(){
    Abc* a1=new Abc[4];
    a1[0]=Abc(1,2);
  return 0;
}
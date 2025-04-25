#include<iostream>
using namespace std;

class Abc{
    int x,y;
    public:
    Abc(int x,int y){
        this->x=x;this->y=y;
    }
    void show(){
        cout<<this->x<<endl;
        cout<<this->y<<endl;
    }
   
};

int main(){
    Abc a1(1,2);
    a1.show();
  return 0;
}
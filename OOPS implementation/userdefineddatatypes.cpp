#include<iostream>
using namespace std;

enum week{
    mon,
    tue,
    wed,
    thu,
    fri,
    sat,
    sun};

union hello{
    int x,y;
};

int main(){
    enum week day;

    day = wed;
    cout<<day;

    union hello h;
    cout<<&h.x<<endl;
    cout<<&h.y<<endl;

  return 0;
}
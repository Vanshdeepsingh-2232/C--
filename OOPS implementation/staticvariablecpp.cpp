#include<iostream>
using namespace std;


class Entity{
    static int x,y;
    public:
    static void get_data(){
        cout<<"The data = "<<x<<" "<<y;
    }
};

int Entity::x;
int Entity::y;

int main(){

    Entity e1;
    e1.get_data();
    

  return 0;
}
#include<iostream>
using namespace std;
// 00`0
// 01`0
// 10`0
// 11`1
//FULL adder
int main(){
    int inputs[8][3]={{0,0,0},{0,0,1},{0,1,0},{0,1,1},{1,0,0},{1,0,1},{1,1,0},{1,1,1}};
    cout<<"``````````````"<<endl;
    cout<<"|A"<<"|B"<<"|C| "<<"|S"<<"|Ca|"<<endl;
    cout<<"``````````````"<<endl;
    for(int i=0;i<8;i++){
      for(int j=0;j<1;j++){
        int a=inputs[i][j],b=inputs[i][j+1],c=inputs[i][j+2];
        
        cout<<"|"<<a<<"|"<<b<<"|"<<c<<"| ";
        cout<<"|"<<(a^b^c);
        cout<<"|"<<(((a^b)&c)+(a&b))<<" |"<<endl;
      }
    }
    
  return 0;
}
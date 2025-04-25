#include<iostream>
#include<string>
using namespace std;

int main(){
    int n;
    cout<<"Enter the n ="; cin>>n;
    try
    {
        if(n==1){
            throw "divide by zero";
        }
        if(n==2){
            throw 101;
        }
        if(n==3){
            throw 'D';
        }
        if(n==4){
            throw 1.1;
        }
    }
    catch(char* str)
    {
        cout<<"Exception string";
    }
    catch(int n)
    {
        cout<<"Exception int";
    }
    catch(char ch)
    {
       cout<<"Exception char" ;
    }
    catch(...)
    {
        cout<<"Exception float";
    }
    
    
  return 0;
}
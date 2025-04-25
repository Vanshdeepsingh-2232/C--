#include<iostream>
#include<string>
using namespace std;


class DivideByZeroExeception{
    private:
        string str="";
    public:
        DivideByZeroExeception(){
        str="Exception Divide by zero";
    }
    string get_msg(){
        return str;
    }
};

int main(){
    int n1,n2;
    cout<<"Enter the number = "<<endl; cin>>n1;
    cout<<"Enter the number = "<<endl; cin>>n2; 
    try {
        if(n1==0 || n2==0){
            throw DivideByZeroExeception();
        }
        cout<<n1/n2;
    }
    catch(DivideByZeroExeception e){
        cout<<"Exception occured is = "<<e.get_msg();
    }
  return 0;
}
#include<iostream>
#include <string>
using namespace std;

string recursive(string &s,int i,int n){
    
    if(i==n) return "";
    string str="";
    str+=s[i];
    return ((s[i]=='a')?"":str)+recursive(s,i+1,n);
}


void Iterative(string &s){
    string str;
    for(int i=0;i<s.length();i++){
        if(s[i]=='a'){
            continue;
        }
        else str += s[i];
    }
    s=str;
}


int main(){
    string st="abcax";
    cout<<recursive(st,0,st.length())<<endl;
    // Iterative(st);
    cout<<st;
  return 0;
}
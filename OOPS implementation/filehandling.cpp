#include<iostream>
#include<fstream>
#include<cstring>

using namespace std;
int main(){

    string str="Hello";
    ofstream out("file.txt");
    out<<str;

    string str2;
    ifstream in("file.txt");
    in>>str2;
    cout<<str2;
    return 0;
}
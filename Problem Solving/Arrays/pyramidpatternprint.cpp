/*
#include<iostream>
#include<math.h>
using namespace std;

/*

_____*
____***
___*****
__*******
_*********
***********
_*********
__*******
___*****
____***
____ *


int main(){
    int n=10;
    int c=0;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            cout<<" ";
        }
        int count=0;
        for(int j=0;j<i+i-1;j++){
            count++;
            cout<<"*";
        }
        // for(int j=0;j<i;j++){cout<<"*";} 
        c=count;
        cout<<c;
        cout<<endl;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            cout<<" ";
        }
        for (int j = i; j < ceil(c/0.5); j++){
            cout<<"*";
        }
        
        cout<<endl;
    }
  return 0;
}
*/


#include <iostream>
#include <windows.h>
void printStars(int count) {
    for (int i = 0; i < count; ++i) {
        std::cout << "*";
        Sleep(100);  // Adjust the delay time here
    }
}
int main() {
    int n;
    std::cout << "Enter the number of rows for the diamond: ";
    std::cin >> n;
    if (n % 2 == 0) {
        std::cout << "Please enter an odd number for a symmetric diamond." << std::endl;
        return 1;
    }
    // Print upper half of the diamond
    for (int i = 1; i <= n; i += 2) {
        for (int j = 0; j < (n - i) / 2; ++j) {
            std::cout << " ";
        }

        printStars(i);

        std::cout << std::endl;
    }
    // Print lower half of the diamond
    for (int i = n - 2; i >= 1; i -= 2) {
        for (int j = 0; j < (n - i) / 2; ++j) {
            std::cout << " ";
        }
        printStars(i);
        std::cout << std::endl;
    }

    return 0;
}




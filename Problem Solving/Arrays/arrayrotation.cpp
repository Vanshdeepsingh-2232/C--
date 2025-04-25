#include<iostream>

using namespace std;

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void reverse(int (&arr)[5],const int &start,const int &end) {

    for(int i = start, j = end; i < j; i++, j--) {
      
        swap(arr[i], arr[j]);
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    cout<<"Enter the rotation number = "<<endl;
    int n;cin<<n;
    
     
    reverse(arr, 0, 4);

    for(int i = 0; i < 5; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}

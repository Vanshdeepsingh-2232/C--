#include<iostream>
using namespace std;

// void iterate(int *arr,int i,int n){
//     if(i==n){
//         return;
//     }
//     cout << arr[i];
//     iterate(arr,i+1,n);
// }

int findmax(int *arr,int i,int n){
  
  if(i==n-1) return arr[i];

  return max(arr[i],findmax(arr,i+1,n));

}

int main(){
  
    int arr[]={1,2,3,4,5};
    int max=arr[0];
    int n=sizeof(arr)/sizeof(arr[0]);
    int i=0;
    // iterate(arr,i,n);
    cout<<findmax(arr,i,n);
  return 0;
}
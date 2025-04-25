#include<iostream>
using namespace std;

int arrSum(int *arr,int i,int n){
    if(i==n-1) return arr[i];

    return arr[i]+arrSum(arr,i+1,n);

}


int main(){
    int arr[]={1,2,3,4,5,6,7};
    cout<<arrSum(arr,0,sizeof(arr)/sizeof(arr[0]));
  return 0;
}
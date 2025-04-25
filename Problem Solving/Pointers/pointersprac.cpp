#include<iostream>
using namespace std;

void revpointer(int *arr,int n){
  for (int i = 0,j = n-1; i < j; i++,j--)
  {
    swap(*(arr+i),*(arr+j));
  }
}
int main(){
  int arr[]={9,8,7,6,5,4,3,2,1};
  int n=(sizeof(arr)/sizeof(arr[0]));
  revpointer(arr,n);
  for (int i = 0; i < n; i++)
  {
    cout<<arr[i];
  }
  return 0;
}
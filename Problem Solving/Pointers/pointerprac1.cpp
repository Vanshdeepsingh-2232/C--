//Q1
// #include<iostream>
// using namespace std;
// int sumpointer(int *arr,int n){
//     int sum;
//   for (int i = 0; i < n; i++)
//   {
//     sum+=(*(arr+i));
//   }
//   return sum;
// }
// int main(){
//   int arr[]={9,8,7,6,5,4,3,2,1};
//   int n=(sizeof(arr)/sizeof(arr[0]));
//   cout<<sumpointer(arr,n);
//   return 0;
// }



//Q2
// #include<iostream>
// using namespace std;
// int main(){
//     int arr[3][3]={{1,2,3},{4,5,6},{7,8,9}};
//     int sum=0;
//     for(int i=0;i<3;i++){
//         sum+=(*((*(arr+i)+i)));
//     }
//     cout<<sum;
//   return 0;
// }




//Q3
// #include<iostream>
// using namespace std;

// void returnabs(int *x,int *y){
//     cout<<((*x)+(*y))<<endl;
//     cout<<abs((*x)-(*y));
// }

// int main(){
//     int a=4,b=5;
//     int* ptr1=&a,*ptr2=&b;
//     returnabs(ptr1,ptr2);
//   return 0;
// }
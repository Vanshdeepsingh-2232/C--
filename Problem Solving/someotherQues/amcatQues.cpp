#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;


int noOfProducts(vector<int> order ,int disAmount){
    int answer=0;

    //code
    for(int i=0;i<order.size();i++){
        if (order[i]>0 && disAmount%order[i]==0)
        {
            answer++;
        }   
    }
    return answer;
}

int main(){
    int order_size=7;
    // cout<<"Enter the order size = ";cin>>order_size;

    vector<int> order={9,-13,8,-7,-8,18,10};
    
    // for(int i=0;i<order_size;i++){
    //     int temp;
    //     cout<<"Enter the number of orders = ";cin>>temp;
    //     order.push_back(temp);
    // }

    int disAmount=18;
    // cout<<"Enter the discount = ";cin>>disAmount;

    int result=noOfProducts(order,disAmount);
    cout<<result;
  return 0;
}
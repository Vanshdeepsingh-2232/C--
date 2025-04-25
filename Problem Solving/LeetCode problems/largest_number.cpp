#include<iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// Input: nums = [10,2]
// Output: "210"

bool compare(int a,int b){
    string s1=to_string(a)+to_string(b);
    string s2=to_string(b)+to_string(a);
    return s1>s2;
}



string largestNumber(vector<int> &nums){
    sort(nums.begin(),nums.end(),compare);
    string result="";
    for(int num: nums){
        result += to_string(num);
    }

    if(result[0]=='0') return "0";
    return result;
}


int main(){
    vector<int> nums={10,2};
    cout<<largestNumber(nums);


  return 0;
}
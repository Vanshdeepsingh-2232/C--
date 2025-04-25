#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;



class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        for(int i=0,j=nums.size()-1 ; i<j ; i++,j--){
            if(nums[i]==nums[j]) return true;
            else return false;
        }
    }
};
int main(){
    Solution s1;
    vector<int> v={1,2,3,1};
    bool b=s1.containsDuplicate(v);
    cout<<b;
  return 0;
}
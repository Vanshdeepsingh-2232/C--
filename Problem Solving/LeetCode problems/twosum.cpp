#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int &target) {
        int n=nums.size();
        vector<int> result(2,0);
        

        if(n==2){
            if(nums[0]+nums[1]==target) {
                result[0]=1;result[1]=2;
                return result;
            }
        }


        sort(nums.begin(),nums.end());
        
        int i=0,j=n-1;
        while(i<j){
            if(nums[i]+nums[j]==target){
                result[0]=i;result[1]=j;
                return result;
            }
            if(nums[i]+nums[j]<target) i++;
            if(nums[i]+nums[j]>target) j--;
        }
        return result;
    }
};


int main(){
    Solution s1;
    int target=5;
    vector<int> nums={3,2};
    int n=nums.size();
    vector<int> result=s1.twoSum(nums,target);
    for (int i = 0; i < result.size(); i++)
    {
        cout<<result[i];
    }
    
  return 0;
}
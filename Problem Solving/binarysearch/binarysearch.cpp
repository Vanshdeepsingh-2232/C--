#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int i=0,j=nums.size()-1; 
        while(i<=j){
            int mid=i+j/2;
            if(nums[mid]==target){
                return mid;
            }
            else if(mid < target) j=mid-1;
            else if(mid > target) i=mid+1;

        }
        return -1;   
    }
};

int main(){
    Solution s1;
    vector<int> v={1,0,3,5,9,12};
    int target =3;
    cout<<s1.search(v,target);
  return 0;
}
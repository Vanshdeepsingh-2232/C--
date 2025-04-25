// Example 1:

// Input: nums = [1,2,3,4]
// Output: [24,12,8,6]
// Example 2:

// Input: nums = [-1,1,0,-3,3]
// Output: [0,0,9,0,0]


#include<iostream>
#include<vector>

using namespace std;
void show(vector<int> v){
        for (auto &n : v) cout<<n<<" ";
        cout<<" ";
    }
    
class Solution {
public:
    vector<int> productExceptSelf(vector<int> &nums) {
        vector<int> left(nums.size(),1);
        vector<int> right(nums.size(),1);
        vector<int> result(nums.size(),1);
        for(int i=1;i<left.size();i++){
            left[i]=nums[i-1]*left[i-1];
        }

        for(int i=nums.size()-2;i>=0;i--){
            right[i]=nums[i+1]*right[i+1];
        }

        for (int i = 0; i < nums.size(); i++)
        {
            result[i]=left[i]*right[i];
        }
        
        return result;
    }
    
};


int main(){
    Solution s1;
    vector<int> nums={1,2,3,4};
    vector<int> r=s1.productExceptSelf(nums);
    show(r);
  return 0;
}
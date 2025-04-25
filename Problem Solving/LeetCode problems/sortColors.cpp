#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        int i=0;
        int j=nums.size()-1;
        int mid=0;

        while(mid<=j){
            if(nums[mid]==0){
                swap(nums[i++],nums[mid++]);
            }
            if(nums[mid]==1){
                mid++;
            }
            if(nums[mid]==2){
                swap(nums[mid++],nums[j--]);
            }
        }
        
    }
};

// Example 1:
// Input: nums = [2,0,2,1,1,0]
// Output: [0,0,1,1,2,2]

// Example 2:
// Input: nums = [2,0,1]
// Output: [0,1,2]

int main()
{
    vector<int> nums={2,0,1};
    Solution s1;
    s1.sortColors(nums);
    for (int i = 0; i < nums.size(); i++)
    {
        cout<<nums[i]<<"__";
    }
    
    return 0;
}
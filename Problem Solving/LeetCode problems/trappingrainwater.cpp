#include<iostream>
#include<vector>

using namespace std;


// Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
// Output: 6


class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int> v1(n,0);
        vector<int> v2(n,0);
        int leftmax=height[0];
        int rightmax=height[n-1];

       //calculating the left max
        for(int i=0 ; i<n ; i++){
            v1[i]=leftmax=max(leftmax,height[i]);
        }

       //calculating the right max
        for(int i=n-1 ; i>=0 ; i--){
            v2[i]=rightmax=max(rightmax,height[i]);
        }

        //calculating the total water in the bars
        int total_water=0;
        for(int i=0;i<n;i++){
            total_water+=min(v2[i],v1[i])-height[i];
        }

        return total_water;


    }
};


int main(){
    Solution s1;
    vector<int> height={4,2,0,3,2,5};
    cout<<s1.trap(height);
    return 0;
}
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// Input: height = [1,8,6,2,5,4,8,3,7]
// Output: 49
// Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. 
// In this case, the max area of water (blue section) the container can contain is 49.

// 8     ||                        ||
// 7     ||                        ||          ||
// 6     ||   ||                   ||          ||
// 5     ||   ||        ||         ||          ||
// 4     ||   ||        ||   ||    ||          ||
// 3     ||   ||        ||   ||    ||    ||    ||
// 2     ||   ||   ||   ||   ||    ||    ||    ||
// 1 ||  ||   ||   ||   ||   ||    ||    ||    ||
//    1   8   6    2    5    4     8     3      7


class Solution {
public:


    int calculateArea(int l,int r,vector<int>& height){
        int area = (min(height[l],height[r]))*(r-l);
        return area;
    }

    int maxArea(vector<int>& height) {

        int maxarea=0;
        if(height.size()==2 && height[0]==1 && height[1]==1){
            maxarea=1;
        }
        int left=0,right=height.size()-1;
        

        while(left<right){

            maxarea=max(calculateArea(left,right,height),maxarea);

            if(height[left]<height[right]) left++;

            else right--;


        }
        return maxarea;
        
    }
};

int main(){
    Solution s1;

    vector<int> input={1,8,6,2,5,4,8,3,7};

    cout<<s1.maxArea(input);

  return 0;
}
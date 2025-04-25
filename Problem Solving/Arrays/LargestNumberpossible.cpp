#include <iostream>
#include <vector>
#include <algorithm>
#include<string>
using namespace std;

bool compareByMod(int a, int b) {
    return a % 10 > b % 10;
}
class Solution {
public:

    string largestNumber(vector<int>& nums) {
        // Sorting the array based on the mod value with respect to 10
        sort(nums.begin(), nums.end(), compareByMod);
        string str = "";
        for (int i = 0; i < nums.size(); i++) {
            // Use push_back or +=
            str += to_string(nums[i]);
        }
        return str;
    }
};



int main() {

    vector<int> nums={3,30,34,5,9};
    Solution s1;
    string ans=s1.largestNumber(nums);
    cout<<ans;
    return 0;
}


/*
Input: nums = [3,30,34,5,9]
Output: "9534330"
*/


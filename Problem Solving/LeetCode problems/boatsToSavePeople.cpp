#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;



class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int boat=0;
        sort(people.begin() , people.end());
        int i=0;
        int j=people.size()-1;
        while(i<=j){
            if(people[i]+people[j] <= limit){
                i++;
            }
            j--;
            boat++;
        }
        return boat;
    }
};





// Example 1:

// Input: people = [1,2], limit = 3
// Output: 1
// Explanation: 1 boat (1, 2)


// Example 2:

// Input: people = [3,2,2,1], limit = 3
// Output: 3
// Explanation: 3 boats (1, 2), (2) and (3)


// Example 3:

// Input: people = [3,5,3,4], limit = 5
// Output: 4
// Explanation: 4 boats (3), (3), (4), (5)




int main(){
    vector<int> v={3,5,3,4};
    Solution s1;
    cout<<s1.numRescueBoats(v,5);
  return 0;
}
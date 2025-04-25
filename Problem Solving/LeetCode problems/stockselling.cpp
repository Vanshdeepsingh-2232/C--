#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//this approach hav some issues :
//this uses the greedy algorithm
//finding first minimum and then maximum from the minimum is a choice to consider
//but in this problem we have to find every possible set of buying and selling index 


// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         int minprice=INT16_MAX , minIndex=-1;
//         for(int i=0;i<prices.size();i++){
//           if(prices[i]<minprice) {
//             minIndex=i;
//             minprice=prices[i];
//           }
//         }
//         int maxprice=minprice;
//         for(int i=minIndex;i<prices.size();i++){
//             if(prices[i]>maxprice) maxprice=prices[i];
//         }
//         return maxprice-minprice;
//     }
// };
class Solution {
public:
    int maxProfit(vector<int>& prices) {
       
    }
};


int main(){

    Solution s1;
    vector<int> prices={7,6,4,3,1};
    cout<<s1.maxProfit(prices);

  return 0;
}


// Input: prices = [7,1,5,3,6,4]
// Output: 5
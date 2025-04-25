#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

class Solution {
public:

    // int find_hours(int t_hour,vector<int> &p){
    //     int total=0;
    //     for (int i = 0; i < p.size(); i++) {
    //         total+=ceil((double)p[i]/(double)t_hour);
    //     }
    //     return total;  
    // }
    //mera solution
    // int minEatingSpeed(vector<int>& piles, int h) {
    //     int range=0;
    //     for(int i=0;i<piles.size();i++){
    //         if(piles[i]>range) range=piles[i];
    //     }

    //     int starting=1,ending=range;
        
    //     while(starting<=ending){
    //         int mid=(starting+ending)/2;
    //         int hours_total=find_hours(mid,piles);
    //         if(hours_total<=h ) ending=mid-1;
    //         else starting=mid+1;
    //     }
    //     return starting;

    // }

    int find_hours(int t_hour, vector<int>& p) {
    long long int total = 0;
    for (int i = 0; i < p.size(); i++) {
        if (t_hour == 1) {
            total += p[i];
        } else {
            total += ceil((double)p[i] / (double)t_hour);
        }
    }
    return total;
}

    int minEatingSpeed(vector<int>& piles, int h) {
    int range = 0;
    for (int i = 0; i < piles.size(); i++) {
        if (piles[i] > range) range = piles[i];
    }

    int starting = 1, ending = range;

    while (starting <= ending) {
        int mid = (starting + ending) / 2;
        long long int hours_total = find_hours(mid, piles);
        cout << "mid: " << mid << ", hours_total: " << hours_total << endl;
        if (hours_total <= h) {
            ending = mid - 1;
        } else {
            starting = mid + 1;
        }
    }
    return starting;
}
};


int main(){
  Solution s1;
  vector<int> pile={805306368,805306368,805306368};
  int hours=1000000000;
  cout<<s1.minEatingSpeed(pile,hours);
  return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <set>
using namespace std;

class Solution
{
public:
    // Function to find equilibrium point in the array.
    int findEquilibrium(vector<int> &arr)
    {
        // code here

        int n=arr.size();
        vector<int>pre(n, 0), suf(n, 0);
        
        int sum=0;
        for(int i=0; i<n; i++){
            pre[i]=sum;
            sum+=arr[i];
        }
        sum=0;
        for(int i=n-1; i>=0; i--){
            suf[i]=sum;
            sum+=arr[i];
        }
        
        for(int i=0; i<n; i++){
            if(pre[i]==suf[i]) return i;
        }
        
        return -1;
    }
};
int main()
{
    vector<int> v = {1, 1, 1, 1};
    Solution s1;
    cout << s1.findEquilibrium(v);
    return 0;
}
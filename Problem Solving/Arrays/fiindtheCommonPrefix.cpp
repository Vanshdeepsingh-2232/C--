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
    vector<int> findThePrefixCommonArray(vector<int> &A, vector<int> &B)
    {

        int n = A.size();
        vector<int> freq(n, 0);
        vector<int> ans;

        for(int i=0;i<n;i++){
            freq[A[i]]++;
            freq[B[i]]++;
            int c=0;
            for(int i=0;i<n;i++){
                if(freq[i]>=2){
                    c++;
                }
            }
            ans.push_back(c);
        }
        return ans;
    }
};

int main()
{
    return 0;
}
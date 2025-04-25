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
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        priority_queue<int,vector<int>, greater<int>> hp;
        vector<int> ans;
        for(int i=0;i<arr.size();i++){
            for(int j=0;j<arr[i].size();j++){
                hp.push(arr[i][j]);
            }
        }
        while (!hp.empty())
        {
            ans.push_back(hp.top());
            hp.pop();
        }
        
        return ans;
    }
};

int main()
{
    return 0;
}
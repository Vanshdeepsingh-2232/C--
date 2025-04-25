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
    int pairWithMaxSum(vector<int> &arr)
    {
        int score = 0, n = arr.size();
        for (int i = 1; i < n; i++)
        {
            score = max(score, arr[i - 1] + arr[i]);
        }
        return score;
    }
};

int main()
{
    vector<int> arr = {4,5,2};
    Solution s1;
    cout << s1.pairWithMaxSum(arr);
    return 0;
}
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
    int tupleSameProduct(vector<int> &nums)
    {
        int n = nums.size();
        unordered_map<int, int> map;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                map[nums[i] * nums[j]]++;
            }
        }
        int tuples = 0;
        for (auto &i : map)
        {
            int product = i.first;
            int freq = i.second;

            tuples += (freq * (freq - 1) / 2);
        }
        return tuples * 8;
    }
};

int main()
{
    vector<int> v = {2, 3, 4, 6};
    Solution s1;
    cout << s1.tupleSameProduct(v);
    return 0;
}
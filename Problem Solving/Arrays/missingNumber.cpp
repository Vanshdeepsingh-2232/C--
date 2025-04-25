#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
            sum += nums[i];

        int n = nums.size();

        int result = 0;
        result = ((n * (n + 1)) / 2) - sum;
        return result;
    }
};

int main()
{
    Solution s1;
    vector<int> v = {1, 0, 3};
    cout << s1.missingNumber(v);
    return 0;
}
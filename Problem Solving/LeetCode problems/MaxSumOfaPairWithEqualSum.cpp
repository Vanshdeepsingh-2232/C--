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
    int find_digit_sum(int n)
    {
        int sum = 0;
        while (n != 0)
        {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }
    int maximumSum(vector<int> &nums)
    {
        int maxSum = 0;
        int n = nums.size();

        unordered_map<int, priority_queue<int>> map;

        for (int i = 0; i < n; i++)
            map[find_digit_sum(nums[i])].push(nums[i]);

        for (auto num : map)
        {
            if (num.second.size() > 1)
            {
                int m1 = num.second.top();
                num.second.pop();
                int m2 = num.second.top();
                if (m1 + m2 > maxSum)
                    maxSum = m1 + m2;
            }
        }

        return maxSum ? maxSum : -1;
    }
};
int main()
{
    vector<int> v = {18, 43, 36, 13, 7};
    Solution s1;
    cout << s1.maximumSum(v);
    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int findMaxConsecutiveOnes(vector<int> &nums)
    {
        int countOne = 0;
        int maxcount = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 1)
            {
                countOne++;
                if (countOne > maxcount)
                    maxcount = countOne;
            }
            else if (nums[i] == 0)
                countOne = 0;
        }
        return maxcount;
    }
};
int main()
{
    vector<int> v = {0, 1, 1, 0, 0, 1, 1, 1, 0};
    Solution s1;
    cout << s1.findMaxConsecutiveOnes(v);
    return 0;
}
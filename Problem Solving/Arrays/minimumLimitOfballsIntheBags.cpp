#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int maxof(vector<int> &v)
    {
        int max = 0;
        for (int &i : v)
            if (i > max)
                max = i;
        return max;
    }
    int minimumSize(vector<int> &nums, int maxOperations)
    {

        int low = 1;
        int high = maxof(nums);
        while (low < high)
        {
            int mid = low + (high - low) / 2;
            int CurrOperations = 0;
            for (int &bag : nums)
            {
                if ((CurrOperations += (bag - 1) / mid) > maxOperations)
                    break;
            }
            if (CurrOperations <= maxOperations)
                high = mid;
            else
                low = mid + 1;
        }

        return high;
    }
};
int main()
{

    vector<int> nums = {2, 4, 8, 2};
    int maxOperations = 4;

    Solution s1;
    cout << s1.minimumSize(nums, maxOperations);
    return 0;
}
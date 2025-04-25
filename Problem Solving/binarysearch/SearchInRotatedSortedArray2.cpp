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
    bool search(vector<int> &nums, int target)
    {

        int n = nums.size();
        int i = 0;
        int j = n - 1;

        while (i <= j)
        {
            int mid = i + (j - i) / 2;

            if (nums[mid] == target)
                return true;
            if ((nums[i] == nums[mid]) && (nums[j] == nums[mid]))
            {
                i++;
                j--;
                continue;
            }

            else if (nums[i] <= nums[mid])
            {
                if (nums[i] <= target && target <= nums[mid])
                {
                    j = mid - 1;
                }
                else
                    i = mid + 1;
            }
            else
            {
                if (nums[mid] <= target && target <= nums[j])
                {
                    i = mid + 1;
                }
                else
                    j = mid - 1;
            }
        }
        return false;
    }
};

int main()
{

    vector<int> v = {2, 5, 6, 0, 0, 1, 2};
    int target = 0;
    Solution s1;
    cout << s1.search(v, target);
    return 0;
}
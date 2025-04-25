#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <set>
using namespace std;

// class Solution
// {
// public:
//     int findMin(vector<int> &nums)
//     {

//         int m = INT32_MAX;

//         int n = nums.size();
//         int i = 0;
//         int j = n - 1;

//         while (i <= j)
//         {
//             int mid = i + (j - i) / 2;
//             if (nums[i] <= nums[mid])
//             {
//                 m = min(m, nums[i]);
//                 i = mid + 1;
//             }
//             else
//             {
//                 m = min(m, nums[mid]);
//                 j = mid - 1;
//             }
//         }
//         return m;
//     }
// };

class Solution
{
public:
    int findKRotation(vector<int> &nums)
    {

        int m = INT32_MAX;

        int n = nums.size();
        int i = 0;
        int j = n - 1;
        int id = 0;

        while (i <= j)
        {
            int mid = i + (j - i) / 2;
            if (nums[i] <= nums[mid])
            {
                if (nums[i] < m)
                {
                    m = nums[i];
                    id = i;
                }
                i = mid + 1;
            }
            else
            {
                if (nums[mid] < m)
                {
                    m = nums[mid];
                    id = mid;
                }
                j = mid - 1;
            }
        }
        return id;
    }
};

int main()
{
    vector<int> v = {3, 4, 5, 1, 2};

    Solution s1;
    cout << s1.findKRotation(v);

    return 0;
}
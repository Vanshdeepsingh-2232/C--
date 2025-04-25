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
    vector<int> majorityElement(vector<int> &nums)
    {
        int ele1 = 0, ele2 = 0;
        int count1 = 0, count2 = 0;

        int n = nums.size();

        for (int i = 0; i < n; i++)
        {
            if (count1 == 0 && nums[i] != ele2)
            {
                ele1 = nums[i];
                count1++;
            }
            else if (count2 == 0 && nums[i] != ele1)
            {
                ele2 = nums[i];
                count2++;
            }
            else if (nums[i] == ele1)
            {
                count1++;
            }
            else if (nums[i] == ele2)
            {
                count2++;
            }
            else
            {
                count1--;
                count2--;
            }
        }
        int c1 = 0, c2 = 0;
        for (int &i : nums)
        {
            if (i == ele1)
                c1++;
            if (i == ele2)
                c2++;
        }

        vector<int> ans;
        if (c1 > (n / 3))
            ans.push_back(ele1);
        if (c2 > (n / 3))
            ans.push_back(ele2);

        return ans;
    }
};

int main()
{
    vector<int> arr = {3, 2, 3};
    Solution s1;
    vector<int> v = s1.majorityElement(arr);
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i];
    }

    return 0;
}
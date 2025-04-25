#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        vector<int> temp;

        int i = 0;
        int j = 0;
        while (i < nums1.size() || j < nums2.size())
        {
            if (nums1[i] <= nums2[j])
            {
                temp.push_back(nums1[i]);
                i++;
            }
            else if (nums1[i] > nums2[j])
            {
                temp.push_back(nums2[j]);
                j++;
            }
        }
        if (i < nums1.size())
        {
            while (i < nums1.size())
                temp.push_back(nums1[i++]);
        }
        if (j < nums2.size())
        {
            while (j < nums2.size())
                temp.push_back(nums2[j++]);
        }

        for (int k = 0; k < temp.size(); k++)
        {
            nums1[k] = temp[k];
        }
    }
};

int main()
{
    vector<int> nums1 = {1, 1, 1};
    vector<int> nums2 = {1, 2, 3};
    int k = 3;
    Solution s1;
    s1.merge(nums1, 3, nums2, 3);
    for (int i = 0; i < nums1.size(); i++)
    {
        cout << nums1[i] << "-";
    }

    return 0;
}
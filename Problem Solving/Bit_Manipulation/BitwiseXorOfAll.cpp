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
    int xorAllNums(vector<int> &nums1, vector<int> &nums2)
    {
        int n1 = nums1.size();
        int n2 = nums2.size();

        int xor1 = 0;
        int xor2 = 0;

        if (n2 % 2 != 0)
        {
            for (int &n : nums1)
            {
                xor1 ^= n;
            }
        }
        if (n1 % 2 != 0)
        {
            for (int &n : nums2)
            {
                xor1 ^= n;
            }
        }

        return xor1 ^ xor2;
    }
};



int main()
{
    return 0;
}
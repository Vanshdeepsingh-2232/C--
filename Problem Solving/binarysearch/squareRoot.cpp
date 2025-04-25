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
    int floorSqrt(int n)
    {
        int i = 1;
        int j = (int)n / 2;
        int r = 0;
        if (n == 0 || n == 1)
            return n;
        while (i <= j)
        {
            int mid = i + (j - i) / 2;
            long long sq = (long long)mid * mid;
            if (sq == n)
                return mid;
            else if (sq < n)
            {
                r = mid;
                i = mid + 1;
            }
            else
                j = mid - 1;
        }
        return r;
    }
};

int main()
{

    int n = 11;
    Solution s1;
    cout << s1.floorSqrt(n);
    return 0;
}
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
    int nthRoot(int n, int m)
    {
        int i = 0;
        int j = m;

        while (i <= j)
        {
            int mid = i + (j - i) / 2;
            int nth = pow(mid, n);
            if (nth == m)
                return mid;
            else if (nth < m)
                i = mid + 1;
            else
                j = mid - 1;
        }

        return -1;
    }
};

int main()
{
    return 0;
}
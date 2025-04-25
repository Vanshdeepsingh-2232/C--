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
    bool isPossible(int day, vector<int> &bloomDay, int m, int k, int n)
    {
        int c = 0;
        int nfb = 0;
        for (int i = 0; i < n; i++)
        {
            if (bloomDay[i] <= day)
            {
                c++;
            }
            else
            {
                nfb += (c / k);
                c = 0;
            }
        }
        nfb += c / k;
        return nfb >= m;
    }
    int minDays(vector<int> &bloomDay, int m, int k)
    {

        int j = *max_element(bloomDay.begin(), bloomDay.end());
        int i = *min_element(bloomDay.begin(), bloomDay.end());
        int n = bloomDay.size();

        if (m * k > n)
            return -1;

        while (i <= j)
        {
            int mid = i + (j - i) / 2;
            if (!isPossible(mid, bloomDay, m, k, n))
                i = mid + 1;
            else
                j = mid - 1;
        }
        return i;
    }
};

int main()
{
    vector<int> bloomday = {1, 10, 3, 10, 2};
    int m = 3, k = 1;
    Solution s1;
    cout << s1.minDays(bloomday, m, k);
    return 0;
}
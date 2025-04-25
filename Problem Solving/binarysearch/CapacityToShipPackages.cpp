#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <set>
#include <numeric>
using namespace std;

class Solution
{
public:
    bool isPossible(vector<int> &weights, int days, int mid)
    {
        int sum = 0;
        int ds = 1;
        for (int i = 0; i < weights.size(); i++)
        {
            if (sum + weights[i] > mid)
            {
                sum = weights[i];
                ds++;
            }
            else
                sum += weights[i];
        }
        return ds <= days;
    }
    int shipWithinDays(vector<int> &weights, int days)
    {

        int i = *max_element(weights.begin(), weights.end());
        int j = accumulate(weights.begin(), weights.end(), 0);
        while (i <= j)
        {
            int mid = i + (j - i) / 2;
            if (isPossible(weights, days, mid))
                j = mid - 1;
            else
                i = mid + 1;
        }
        return i;
    }
};

int main()
{
    vector<int> weights = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int days = 5;
    Solution s1;
    cout << s1.shipWithinDays(weights, days);

    // cout << s1.isPossible(weights, days, 10);
    return 0;
}
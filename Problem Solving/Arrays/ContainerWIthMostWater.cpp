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
    int maxWater(vector<int> &arr)
    {
        int n = arr.size();
        int i = 0;
        int j = n - 1;
        int m = 0;
        while (i < j)
        {
            int d = (j - i) * (min(arr[i], arr[j]));
            m = max(m, d);
            if (arr[j] <= arr[i])
                j--;
            else
                i++;
        }
        return m;
    }
};
int main()
{
    vector<int> v = {2, 1, 8, 6, 4, 6, 5, 5};
    Solution s1;
    cout << s1.maxWater(v);
    return 0;
}
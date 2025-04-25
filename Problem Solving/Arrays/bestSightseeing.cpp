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
    int maxScoreSightseeingPair(vector<int> &values)
    {
        int ans = 0;
        int n = values.size();
        int maxi = values[0] + 0;
        for (int j = 1; j < n; j++)
        {
            if (values[j - 1] + (j - 1) > maxi)
                maxi = values[j - 1] + (j - 1);
            ans = max(ans, maxi + values[j] - j);
        }
        return ans;
    }
};

int main()
{
    vector<int> values = {8, 1, 5, 2, 6};
    Solution s1;
    cout << s1.maxScoreSightseeingPair(values);
    return 0;
}
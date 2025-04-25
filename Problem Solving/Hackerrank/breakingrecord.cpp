// 0 9 3 10 2 20

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

vector<int> breakingRecords(vector<int> scores)
{
    int n = scores.size();
    vector<int> ans(2, 0);

    int max = -1, maxcount = 0, min = INT32_MAX, mincount = 0;
    for (int i = 0, j = 0; i < n; i++, j++)
    {
        if (scores[i] > max)
        {
            max = scores[i];
            maxcount++;
        }
        if (scores[j] < min)
        {
            min = scores[j];
            mincount++;
        }
    }

    ans = {maxcount - 1, mincount - 1};
    return ans;
}

int main()
{
    vector<int> score = {0, 9, 3, 10, 2, 20};
    vector<int> ans = breakingRecords(score);
    cout << ans[0] << ' ' << ans[1];
    return 0;
}
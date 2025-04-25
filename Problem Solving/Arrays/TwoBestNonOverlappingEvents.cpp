#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int maxTwoEvents(vector<vector<int>> &events)
    {
        int n = events.size();

        sort(events.begin(), events.end(), [](const vector<int> &a, const vector<int> &b)
             { return a[0] < b[0]; });

        vector<int> suffixMax(n);
        suffixMax[n - 1] = events[n - 1][2];

        for (int i = n - 2; i >= 0; --i)
        {
            suffixMax[i] = max(events[i][2], suffixMax[i + 1]);
        }

        for (int i = 0; i < suffixMax.size(); i++)
        {
            cout << suffixMax[i];
        }
        cout << "-------------------------------------" << endl;

        int maxSum = 0;

        for (int i = 0; i < n; ++i)
        {
            int left = i + 1, right = n - 1;
            int nextEventIndex = -1;

            while (left <= right)
            {
                int mid = left + (right - left) / 2;
                if (events[mid][0] > events[i][1])
                {
                    nextEventIndex = mid;
                    right = mid - 1;
                }
                else
                {
                    left = mid + 1;
                }
            }

            if (nextEventIndex != -1)
            {
                maxSum = max(maxSum, events[i][2] + suffixMax[nextEventIndex]);
            }

            maxSum = max(maxSum, events[i][2]);
        }

        return maxSum;
    }
};

int main()
{
    vector<vector<int>> events = {{1, 3, 2},
                                  {4, 5, 2},
                                  {2, 4, 3}};
    vector<vector<int>> events2 = {{1, 3, 2},
                                   {4, 5, 2},
                                   {1, 5, 5}};
    vector<vector<int>> events3 = {{1, 5, 3},
                                   {1, 5, 1},
                                   {6, 6, 5}};

    Solution s1;
    cout << s1.maxTwoEvents(events);
    cout << s1.maxTwoEvents(events2);
    cout << s1.maxTwoEvents(events3);
    return 0;
}
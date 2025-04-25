#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <stack>
using namespace std;

class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {
        stack<int> pse;
        int rectArea = 0;
        int n = heights.size();

        for (int i = 0; i < n; i++)
        {
            while (!pse.empty() && heights[i] < heights[pse.top()])
            {
                int Nse = i;
                int ele = pse.top();
                pse.pop();

                int Pse = pse.empty() ? -1 : pse.top();
                rectArea = max(rectArea, (heights[ele] * (Nse - Pse - 1)));
            }
            pse.push(i);
        }

        while (!pse.empty())
        {
            int ele = pse.top();
            pse.pop();

            int Nse = n;
            int Pse = pse.empty() ? -1 : pse.top();

            rectArea = max(rectArea, (heights[ele] * (Nse - Pse - 1)));
        }

        return rectArea;
    }
};

int main()
{

    vector<int> v = {2, 1, 5, 6, 2, 3};
    Solution s1;
    cout << s1.largestRectangleArea(v);

    return 0;
}
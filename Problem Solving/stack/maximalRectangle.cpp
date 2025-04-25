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
    int largestAreaHistogram(vector<int> &heights)
    {

        int maxArea = 0;
        stack<int> st;
        int n = heights.size();
        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && heights[i] < heights[st.top()])
            {
                int nse = i;
                int ele = st.top();
                st.pop();
                int pse = (st.empty()) ? -1 : st.top();

                maxArea = max(maxArea, heights[ele] * (nse - pse - 1));
            }
            st.push(i);
        }

        while (!st.empty())
        {
            int ele = st.top();
            st.pop();
            int nse = n;
            int pse = (st.empty()) ? -1 : st.top();

            maxArea = max(maxArea, heights[ele] * (nse - pse - 1));
        }

        return maxArea;
    }
    int maximalRectangle(vector<vector<char>> &matrix)
    {
        if (matrix.empty())
            return 0;
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> heights(m, 0);
        int maxRect = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                heights[j] = (matrix[i][j] == '1') ? (heights[j] + 1) : 0;
            }

            maxRect = max(maxRect, largestAreaHistogram(heights));
        }

        return maxRect;
    }
};

int main()
{

    vector<vector<char>> matrix = {{'1', '0', '1', '0', '0'},
                                   {'1', '0', '1', '1', '1'},
                                   {'1', '1', '1', '1', '1'},
                                   {'1', '0', '0', '1', '0'}};

    Solution s1;
    cout << s1.maximalRectangle(matrix);
    return 0;
}
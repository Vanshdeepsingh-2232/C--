#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    unordered_map<int, pair<int, int>> reserved;

    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {

        int first = intervals[0][0];
        int second = intervals[0][1];
        reserved[1] = make_pair(first, second);


        for (int i = 0; i < intervals.size(); i++)
        {
            int first = intervals[i][0];
            int second = intervals[i][1];

        }
    }
};

int main()
{
    return 0;
}
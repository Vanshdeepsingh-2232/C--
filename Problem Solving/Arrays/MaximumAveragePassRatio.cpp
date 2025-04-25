#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>

#define P pair<double, pair<int, int>>
using namespace std;

// brute force solution
// i have to track the class which is having the
// maximum improvement after adding the brilliant students
// this approach is slow and gives TLE

// class Solution
// {
// public:
//     double maxAverageRatio(vector<vector<int>> &classes, int extraStudents)
//     {
//         int n = classes.size();
//         double ans = 0.0;
//         while (extraStudents--)
//         {
//             P maximp = {0.0, 0};
//             for (int i = 0; i < n; i++)
//             {
//                 double curr_delta = (double)classes[i][0] / classes[i][1];
//                 double new_delta = (double)(classes[i][0] + 1) / (double)(classes[i][1] + 1);
//                 double improvement = new_delta - curr_delta;
//                 if (improvement > maximp.first)
//                 {
//                     maximp.first = improvement;
//                     maximp.second = i;
//                 }
//             }
//             classes[maximp.second][0]++;
//             classes[maximp.second][1]++;
//         }
//         double deltaSum = 0.0;
//         for (auto &i : classes)
//         {
//             double p = i[0];
//             double q = i[1];
//             deltaSum += (double)p / q;
//         }
//         ans = (double)deltaSum / n;
//         return ans;
//     }
// };

class Solution
{
public:
    double improvement(int p, int q)
    {
        return (double)(p + 1) / (q + 1) - (double)p / q;
    }

    double maxAverageRatio(vector<vector<int>> &classes, int extraStudents)
    {
        priority_queue<P> heap;
        int n = classes.size();
        for (auto &i : classes)
            heap.push({improvement(i[0], i[1]), {i[0], i[1]}});

        while (extraStudents--)
        {
            auto [imprv, cls] = heap.top();
            heap.pop();
            int p = cls.first;
            int q = cls.second;

            p++;
            q++;
            heap.push({improvement(p, q), {p, q}});
        }

        double ratio = 0.0;
        while (!heap.empty())
        {
            auto [_, cls] = heap.top();
            heap.pop();
            ratio += (double)cls.first / cls.second;
        }
        return ratio / n;
    }
};
int main()
{
    vector<vector<int>> classes = {{1, 2}, {3, 5}, {2, 2}};
    int extraStudents = 2;
    Solution s1;
    cout << s1.maxAverageRatio(classes, extraStudents);
    return 0;
}
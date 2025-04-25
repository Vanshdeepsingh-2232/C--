#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

// THIS APPROACH IS SLOW EVEN AFTER SOME MODIFICATIONS

class Solution
{
public:
    vector<int> kthSmallestPrimeFraction(vector<int> &arr, int k)
    {
        vector<int> answer;
        set<pair<double, vector<int>>> fractions;
        for (int i = 0; i < arr.size(); i++)
        {
            for (int j = i + 1; j < arr.size(); j++)
            {
                fractions.insert(make_pair((double)arr[i] / (double)arr[j], vector<int>{arr[i], arr[j]}));
            }
        }
        auto it = fractions.begin();
        advance(it, k - 1);
        pair<double, vector<int>> thirdElement = *it;
        for (const auto &num : thirdElement.second)
        {
            answer.push_back(num);
           
        }
        return answer;
    }
};

// VERY FAST APPROACH

// class Solution {
// public:
//     vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
//         vector<int> answer;

//         // Use a sliding window approach to find the kth smallest prime fraction
//         int n = arr.size();
//         double left = 0, right = 1;
//         while (right - left > 1e-9) {
//             double mid = left + (right - left) / 2;
//             int count = 0, p = -1, q = -1, j = 1;

//             // Use sliding window to count the number of fractions less than or equal to mid
//             for (int i = 0; i < n - 1; ++i) {
//                 while (j < n && arr[i] > mid * arr[j]) ++j;
//                 count += n - j;
//                 if (j < n && (p == -1 || arr[p] * arr[j] < arr[q] * arr[i])) {
//                     p = i;
//                     q = j;
//                 }
//             }

//             // If the count is less than k, update the left range
//             if (count < k) left = mid;
//             // If the count is greater than or equal to k, update the right range
//             else right = mid;

//             // If the count is exactly k, store the result
//             if (count == k) answer = {arr[p], arr[q]};
//         }

//         return answer;
//     }
// };

int main()
{
    Solution s1;

    vector<int> n = {1, 2, 3, 5};

    int k = 3;
    s1.kthSmallestPrimeFraction(n, k);

    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Example 1:

// Input: happiness = [1,2,3], k = 2
// Output: 4
// Explanation: We can pick 2 children in the following way:
// - Pick the child with the happiness value == 3. The happiness value of the remaining children becomes [0,1].
// - Pick the child with the happiness value == 1. The happiness value of the remaining child becomes [0]. Note that the happiness value cannot become less than 0.
// The sum of the happiness values of the selected children is 3 + 1 = 4.

// Example 2:

// Input: happiness = [1,1,1,1], k = 2
// Output: 1
// Explanation: We can pick 2 children in the following way:
// - Pick any child with the happiness value == 1. The happiness value of the remaining children becomes [0,0,0].
// - Pick the child with the happiness value == 0. The happiness value of the remaining child becomes [0,0].
// The sum of the happiness values of the selected children is 1 + 0 = 1.

// Example 3:

// Input: happiness = [2,3,4,5], k = 1
// Output: 5
// Explanation: We can pick 1 child in the following way:
// - Pick the child with the happiness value == 5. The happiness value of the remaining children becomes [1,2,3].
// The sum of the happiness values of the selected children is 5.

class Solution {
public:
    long long maximumHappinessSum(vector<int> &happiness, int k) {
        sort(happiness.begin(), happiness.end());
        long long sum_selected = 0;
        long long i = happiness.size() - 1;
        int dec = 0;
        while (k--) {
            if (happiness[i] - dec > 0)
                sum_selected += happiness[i--] - dec++;
            else
                sum_selected += happiness[i--];
        }
        return sum_selected;
    }
};



int main()
{
    vector<int> v{12,1,42};
    int k = 3;
    Solution s1;
    cout<<s1.maximumHappinessSum(v, k);

    return 0;
}
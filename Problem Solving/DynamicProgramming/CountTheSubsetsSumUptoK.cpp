#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <set>
#include <stack>
using namespace std;

// class Solution
// {
// public:
//     int f(vector<int> &arr, int K, int i)
//     {

//         if (i == 0)
//             return arr[i] == K;
//         if (K == 0)
//             return 1;

//         int nonpick = f(arr, K, i - 1);
//         int pick = 0;
//         if (arr[i] <= K)
//             pick = f(arr, K - arr[i], i - 1);

//         return pick + nonpick;
//     }
//     int perfectSum(vector<int> &arr, int K)
//     {

//         int n = arr.size();
//         int ind = n - 1;

//         return f(arr, K, ind);
//     }
// };

// class Solution
// {
// public:
//     int f(vector<int> &arr, int K, int i, vector<vector<int>> &dp)
//     {
//         if (i == 0)
//         {
//             if (K == 0 && arr[0] == 0)
//                 return 2;
//             if (K == 0 || arr[0] == K)
//                 return 1;
//             return 0;
//         }
//         if (dp[i][K] != -1)
//             return dp[i][K];
//         int nonpick = f(arr, K, i - 1, dp);
//         int pick = 0;
//         if (arr[i] <= K)
//             pick = f(arr, K - arr[i], i - 1, dp);

//         return dp[i][K] = pick + nonpick;
//     }
//     int perfectSum(vector<int> &arr, int K)
//     {
//         int n = arr.size();
//         int ind = n - 1;
//         vector<vector<int>> dp(n, vector<int>(K + 1, -1));
//         return f(arr, K, ind, dp);
//     }
// };

class Solution
{
public:
    // int f(vector<int> &arr, int K, int i, vector<vector<int>> &dp)
    // {
    //     if (i == 0)
    //     {
    //         if (K == 0 && arr[0] == 0)
    //             return 2;
    //         if (K == 0 || arr[0] == K)
    //             return 1;
    //         return 0;
    //     }

    //     if (dp[i][K] != -1)
    //         return dp[i][K];
    //     int nonpick = f(arr, K, i - 1, dp);
    //     int pick = 0;
    //     if (arr[i] <= K)
    //         pick = f(arr, K - arr[i], i - 1, dp);

    //     return dp[i][K] = pick + nonpick;
    // }

    int perfectSum(vector<int> &arr, int K)
    {
        int n = arr.size();
        int ind = n - 1;
        vector<vector<int>> dp(n, vector<int>(K + 1, 0));
        for (int i = 0; i < n; i++)
            dp[i][0] = 1;
        if (arr[0] <= K)
            dp[0][arr[0]] = 1;

        for (int i = 1; i < n; i++)
        {
            for (int s = 0; s <= K; s++)
            {
                int nonpick = dp[i - 1][s];
                int pick = 0;
                if (arr[i] <= s)
                    pick = dp[i - 1][s - arr[i]];
                dp[i][s] = pick + nonpick;
            }
        }

        return dp[n - 1][K];
    }
};

int main()
{

    vector<int> v = {1, 2, 3, 4, 5};
    int k = 5;

    Solution s1;
    cout << s1.perfectSum(v, k);

    return 0;
}
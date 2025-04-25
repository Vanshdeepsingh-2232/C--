#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to solve 0/1 Knapsack problem using dynamic programming
int knapsack(int capacity, vector<int>& weights, vector<int>& values, int n) {
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));

    for (int i = 1; i <= n; ++i) {
        for (int w = 1; w <= capacity; ++w) {
            if (weights[i - 1] <= w) {
                dp[i][w] = max(values[i - 1] + dp[i - 1][w - weights[i - 1]], dp[i - 1][w]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[n][capacity];
}

int main() {
    vector<int> values = {60, 100, 120};
    vector<int> weights = {10, 20, 30};
    int capacity = 50;
    int n = values.size();

    int maxValue = knapsack(capacity, weights, values, n);
    cout << "Maximum value in knapsack = " << maxValue << endl;

    return 0;
}

#include <iostream>
#include <vector>

using namespace std;

const int INF = 1e9; // Define infinity as a very large number

// Function to find the minimum number of scalar multiplications needed to multiply a chain of matrices
int matrixChainOrder(const vector<int>& dims) {
    int n = dims.size() - 1; // Number of matrices

    // Create a 2D DP table to store the minimum number of scalar multiplications
    vector<vector<int>> dp(n, vector<int>(n, 0));

    // Fill the DP table in a bottom-up manner
    // The main idea is to divide the chain at each possible position and find the optimal substructure
    for (int len = 2; len <= n; ++len) {
        for (int i = 0; i < n - len + 1; ++i) {
            int j = i + len - 1;
            dp[i][j] = INF; // Initialize with a large value
            for (int k = i; k < j; ++k) {
                int cost = dp[i][k] + dp[k + 1][j] + dims[i] * dims[k + 1] * dims[j + 1];
                if (cost < dp[i][j]) {
                    dp[i][j] = cost;
                }
            }
        }
    }

    // The result is stored in the top-right cell of the DP table
    return dp[0][n - 1];
}

int main() {
    // Example dimensions of matrices: A1(10x30), A2(30x5), A3(5x60)
    vector<int> dims = {10, 30, 5, 60};

    // Calculate the minimum number of scalar multiplications
    int minScalarMult = matrixChainOrder(dims);

    cout << "Minimum number of scalar multiplications: ";
    if (minScalarMult == INF) {
        cout << "Impossible" << endl;
    } else {
        cout << minScalarMult << endl;
    }

    return 0;
}

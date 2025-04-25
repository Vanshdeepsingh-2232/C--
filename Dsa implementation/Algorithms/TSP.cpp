#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

const int INF = 1e9; // Define infinity as a very large number

// Function to calculate distance between two points
double distance(pair<int, int>& a, pair<int, int>& b) {
    return sqrt(pow(a.first - b.first, 2) + pow(a.second - b.second, 2));
}

// Function to solve the Traveling Salesman Problem using dynamic programming
double tsp(vector<vector<double>>& graph, int n) {
    // Create DP table to store the minimum cost of visiting each city
    vector<vector<double>> dp(1 << n, vector<double>(n, INF));

    // Initialize DP table for the starting city
    dp[1][0] = 0;

    // Iterate through all subsets of cities
    for (int mask = 1; mask < (1 << n); ++mask) {
        for (int i = 0; i < n; ++i) {
            if (mask & (1 << i)) {
                for (int j = 0; j < n; ++j) {
                    if (mask & (1 << j)) {
                        dp[mask][i] = min(dp[mask][i], dp[mask ^ (1 << i)][j] + graph[j][i]);
                    }
                }
            }
        }
    }

    // Find the minimum cost to return to the starting city
    double minCost = INF;
    for (int i = 0; i < n; ++i) {
        minCost = min(minCost, dp[(1 << n) - 1][i] + graph[i][0]);
    }

    return minCost;
}

int main() {
    int n = 4; // Number of cities

    // Coordinates of each city
    vector<pair<int, int>> cities = {{0, 0}, {1, 2}, {3, 1}, {2, 3}};

    // Calculate distance between each pair of cities
    vector<vector<double>> graph(n, vector<double>(n, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            graph[i][j] = distance(cities[i], cities[j]);
        }
    }

    // Solve the TSP and output the minimum cost
    double minCost = tsp(graph, n);
    cout << "Minimum cost of traveling: " << minCost << endl;

    return 0;
}

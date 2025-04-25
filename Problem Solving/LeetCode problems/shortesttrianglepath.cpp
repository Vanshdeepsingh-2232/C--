#include<iostream>
#include<vector>
using namespace std;

int minimumTotal(vector<vector<int>>& triangle) {
    int height = triangle.size();
    vector<vector<int>> dp(height, vector<int>(height, height+1));
    for (int i = 0; i < height; i++) {
        dp[height - 1][i] = triangle[height - 1][i];
    }
    for (int level = height - 2; level >= 0; level--) {
        for (int i = 0; i <= level; i++) {
            dp[level][i] = triangle[level][i] + min(dp[level + 1][i], dp[level + 1][i + 1]);
        }
    }
    return dp[0][0];
}
int main(){
    vector<vector <int>> arr
    {
        {-1},
        {2,3},
        {1,-1,-3}
    };
    cout<<minimumTotal(arr);
    return 0;
}
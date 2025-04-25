#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


// Example 1:

// Input: text1 = "abcde", text2 = "ace"
// Output: 3
// Explanation: The longest common subsequence is "ace" and its length is 3.
// Example 2:

// Input: text1 = "abc", text2 = "abc"
// Output: 3
// Explanation: The longest common subsequence is "abc" and its length is 3.
// Example 3:

// Input: text1 = "abc", text2 = "def"
// Output: 0
// Explanation: There is no such common subsequence, so the result is 0.

class Solution
{
public:
    void printMatrix(const vector<vector<int>> &matrix)
    {
        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix[i].size(); j++)
            {
                cout << matrix[i][j];
            }
            cout << endl;
        }
    }
 
    int longestCommonSubsequence(string &text1, string &text2)
    {
      
        vector<vector<int>> matrix(text1.size() + 1, vector<int>(text2.size() + 1, 0));
        for (int i = 1; i < matrix.size(); i++)
        {
            for (int j = 1; j < matrix[i].size(); j++)
            {
                if (text1[i - 1] == text2[j - 1])
                {
                    matrix[i][j] = matrix[i - 1][j - 1]+1;
                }
                else
                {
                    matrix[i][j] = max(matrix[i - 1][j], matrix[i][j - 1]);
                }
            }
        }
        return matrix[text1.size()][text2.size()];
    }
};

int main()
{
    Solution s1;
    string text1 = "abcde", text2 = "ace";
    cout<<s1.longestCommonSubsequence(text1, text2);
    return 0;
}
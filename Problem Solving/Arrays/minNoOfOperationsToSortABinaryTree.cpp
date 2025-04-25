#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <set>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution
{
public:
    int findSwaps(vector<int> &level)
    {
        int swaps = 0;
        int n = level.size();
        vector<int> sorted(level.begin(), level.end());
        sort(sorted.begin(), sorted.end());
        unordered_map<int, int> map;
        for (int i = 0; i < n; i++)
            map[level[i]] = i;
        int i = 0;
        int j = 0;
        while (i < n)
        {
            if (level[i] == sorted[j])
            {
                i++;
                j++;
            }
            else
            {
                swap(level[i], level[map[sorted[j]]]);
                map[sorted[j]] = i;
                map[level[i]] = j;
                swaps++;
            }
        }
        return swaps;
    }
    int minimumOperations(TreeNode *root)
    {
        queue<TreeNode *> q;
        q.push(root);
        int swaps = 0;
        while (!q.empty())
        {
            vector<int> level;
            int n = q.size();
            while (n--)
            {
                auto front = q.front();
                q.pop();
                level.push_back(front->val);
                // fill the queue
                if (front->left)
                    q.push(front->left);
                if (front->right)
                    q.push(front->right);
                swaps = findSwaps(level);
            }
        }

        return swaps;
    }
};

int main()
{
    return 0;
}
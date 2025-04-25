#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <set>
#include <stack>
using namespace std;

// best approach
//  class Solution
//  {
//  public:
//      int maxChunksToSorted(vector<int> &arr)
//      {
//          int chunks = 1;
//          int maxElement = 0;
//          int n = arr.size();

//         for (int i = 0; i < n; i++)
//         {
//             if (arr[i] > maxElement)
//             {
//                 maxElement = arr[i];
//                 if (i == maxElement)
//                 {
//                     chunks++;
//                 }
//             }
//         }
//         return chunks;
//     }
// };

class Solution
{
public:
    int maxChunksToSorted(vector<int> &arr)
    {
        stack<int> st;

        for (int i = 0; i < arr.size(); i++)
        {
            int maxele = 0;
            if (st.empty() || arr[i] > st.top())
                st.push(arr[i]);

            else
            {
                maxele = st.top();
                while (!st.empty() && arr[i] < st.top())
                    st.pop();
                st.push(maxele);
            }
        }
        return st.size();
    }
};

int main()
{
    vector<int> arr = {4, 3, 2, 1, 0};
    Solution s1;
    cout << s1.maxChunksToSorted(arr);
    return 0;
}
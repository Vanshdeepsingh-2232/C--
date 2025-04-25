#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <set>
using namespace std;

// tle somehow
//  class Solution
//  {
//  public:
//      vector<int> countDistinct(vector<int> &arr, int k)
//      {
//          int n = arr.size();
//          vector<int> ans;
//          for (int i = 0; i + k <= n; i++)
//          {
//              set<int> s;
//              int j=k;
//              int m=i;
//              while (j--)
//              {
//                  s.insert(arr[m++]);
//              }
//              ans.push_back(s.size());
//          }
//          return ans;
//      }
//  };

class Solution
{
public:
    vector<int> countDistinct(vector<int> &arr, int k)
    {
        int n = arr.size();
        vector<int> ans;
        unordered_map<int, int> map;
        for (int j = 0; j < k; j++)
            map[arr[j]]++;
        ans.push_back(map.size());
        for (int i = 0, j = k; j < n; i++, j++)
        {
            map[arr[i]]--;
            if (map[arr[i]] == 0)
                map.erase(arr[i]);
            map[arr[j]]++;
            ans.push_back(map.size());
        }

        return ans;
    }
};


int main()
{
    vector<int> v = {1, 2, 1, 3, 4, 2, 3};
    int k = 4;
    Solution s1;
    vector<int> ans = s1.countDistinct(v, k);
    for (auto i : ans)
        cout << i;
    return 0;
}
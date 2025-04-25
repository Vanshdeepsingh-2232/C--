#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <set>
#include <map>
using namespace std;

class Solution
{
public:
  int beauty(vector<int> &map)
  {
    int m = *max_element(map.begin(), map.end());
    int mi = INT32_MAX;
    for (int i = 0; i < 27; i++)
      if (map[i] < mi && map[i] != 0)
        mi = map[i];

    return (m - mi);
  }
  int beautySum(string s)
  {
    int n = s.size();
    vector<int> map(26 + 1, 0);
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
      vector<int> map(26 + 1, 0);
      for (int j = i; j < n; j++)
      {
        map[s[j] - 'a']++;
        sum += beauty(map);
      }
    }
    return sum;
  }
};

int main()
{
  string s = "aabcb";
  string s2 = "aabcbaa";
  Solution s1;
  cout << s1.beautySum(s);
  return 0;
}
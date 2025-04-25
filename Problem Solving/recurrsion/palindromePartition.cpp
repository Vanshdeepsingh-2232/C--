#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution
{

public:
  bool isPalindrome(string s, int start, int end)
  {
    for (int i = start, j = end; i <= j; i++, j--)
    {
      if (s[i] != s[j])
        return false;
    }
    return true;
  }
  void create_partitions(int index, string s, vector<string> &partitions, vector<vector<string>> &result)
  {
    if (index == s.size())
    {
      result.push_back(partitions);
      return;
    }
    for (int i = index; i < s.size(); i++)
    {
      if (isPalindrome(s, index, i))
      {
        partitions.push_back(s.substr(index, i - index + 1));
        create_partitions(i + 1, s, partitions, result);
        partitions.pop_back();
      }
    }
  }
  vector<vector<string>> partition(string s)
  {
    vector<vector<string>> result;
    vector<string> partitions;
    int index = 0;
    create_partitions(index, s, partitions, result);
    return result;
  }
};
int main()
{
  Solution s1;
  string s = "efe";
  vector<vector<string>> ans = s1.partition(s);
  for (int i = 0; i < ans.size(); i++)
  {
    for (int j = 0; j < ans[i].size(); j++)
    {
      cout << ans[i][j] << "-";
    }
    cout << endl;
  }

  cout << s1.isPalindrome("efe", 0, 2);
  return 0;
}
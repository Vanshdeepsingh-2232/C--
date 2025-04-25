#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <set>
using namespace std;
// BRUTE FORCE SOLUTION GOT TLE

//  class Solution
//  {
//  public:
//      void shift(int start, int end, int di, string &s)
//      {
//          for (int i = start; i <= end; i++)
//          {
//              if (di == 1)
//              {
//                  int currChar = (s[i] - 'a');
//                  if ((currChar + 1) > 25)
//                  {
//                      s[i] = 'a';
//                      continue;
//                  }
//                  int newChar = (currChar + 1) + 'a';
//                  s[i] = newChar;
//              }
//              else
//              {
//                  int currChar = (s[i] - 'a');
//                  if (currChar - 1 < 0)
//                  {
//                      s[i] = 'z';
//                      continue;
//                  }
//                  int newChar = (currChar - 1) + 'a';
//                  s[i] = newChar;
//              }
//          }
//      }
//      string shiftingLetters(string s, vector<vector<int>> &shifts)
//      {
//          vector<char> c = {};
//          for (vector<int> &i : shifts)
//              shift(i[0], i[1], i[2], s);
//          return s;
//      }
//  };

// approach  two involves the diffrence array technique
class Solution
{
public:
    string shiftingLetters(string s, vector<vector<int>> &shifts)
    {

        int n = s.size();
        vector<int> diff(n, 0);

        for (auto &s : shifts)
        {
            int dir = s[2];
            int x = 0;
            if (dir == 0)
                x = -1;
            else
                x = 1;
            diff[s[0]] += x;
            if (s[1] + 1 < n)
                diff[s[1] + 1] -= x;
        }
        for (int i = 1; i < n; i++)
            diff[i] = diff[i - 1] + diff[i];
        for (int i = 0; i < n; i++)
        {
            int shift = diff[i] % 26;
            if (shift < 0)
                shift += 26;

            s[i] = ((s[i] - 'a') + shift) % 26 + 'a';
        }
        return s;
    }
};

int main()
{

    string s = "abc";
    vector<vector<int>> shifts = {{0, 1, 0},
                                  {1, 2, 1},
                                  {0, 2, 1}};

    Solution s1;
    cout << s1.shiftingLetters(s, shifts);
    return 0;
}
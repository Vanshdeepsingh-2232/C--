#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    // TLE
    //  string addSpaces(string s, vector<int> &spaces)
    //  {
    //      for (int i = 0; i < spaces.size(); i++)
    //      {
    //          auto it = s.insert(s.begin() + spaces[i] + i, ' ');
    //      }
    //      return s;
    //  }

    string addSpaces(string s, vector<int> &spaces)
    {
        string str = "";
        // spaces[i]+i

        int i = 0;
        int j = 0;
        int k = 0;

        while (j < s.size())
        {
            if (k < spaces.size() && i == spaces[k] + k)
            {
                str.push_back(' ');
                i++;
                k++;
            }
            else
            {
                str.push_back(s[j++]);
                i++;
            }
        }
        return str;
    }
};


//another optimized
// class Solution
// {
// public:
//     string addSpaces(string s, vector<int> &spaces)
//     {
//         string result;
//         result.reserve(s.size() + spaces.size()); // Reserve space to avoid reallocations

//         int k = 0, n = spaces.size();
//         for (int i = 0; i < s.size(); i++)
//         {
//             // Add a space if the current index matches the next space index
//             if (k < n && i == spaces[k])
//             {
//                 result.push_back(' ');
//                 k++;
//             }
//             result.push_back(s[i]);
//         }

//         return result;
//     }
// };


int main()
{
    // string s = "spacing";
    string s = "icodeinpython";
    vector<int> spaces = {1, 5, 7, 9};
    Solution s1;
    cout << s1.addSpaces(s, spaces);
    return 0;
}
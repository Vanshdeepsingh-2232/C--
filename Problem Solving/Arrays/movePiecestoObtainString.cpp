#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    bool canChange(string start, string target)
    {
        if (start == target)
            return true;
        bool ans = true;
        int i = 0;
        int j = 0;
        int n = start.size();

        while (i < n || j < n)
        {
            if (start[i] == '_')
                i++;
            if (target[j] == '_')
                j++;

            if ((start[i] == 'L' && target[j] == 'R') || (start[i] == 'R' && target[j] == 'L'))
            {
                ans = false;
                break;
            }
            if (start[i] == 'L' && target[j] == 'L')
            {
                if (i < j)
                {
                    ans = false;
                    break;
                }
                else
                {
                    if (i < n)
                        i++;
                    if (j < n)
                        j++;
                }
            }
            if (start[i] == 'R' && target[j] == 'R')
            {
                if (i > j)
                {
                    ans = false;
                    break;
                }
                else
                {
                    if (i < n)
                        i++;
                    if (j < n)
                        j++;
                }
            }
        }
        return ans;
    }
};

int main()
{
    Solution s1;
    string start = "_L__R__R_";
    string target = "L______RR";

    // string start = "R_L_";
    // string target = "__LR";

    cout << s1.canChange(start, target);
    return 0;
}


// class Solution {
// public:
//     bool canChange(string start, string target) {
//         int i = 0, j = 0, n = start.size();
	
//         while(i < n || j < n){
            
//             while(i < n && start[i] == '_')
//                 i++;
//             while(j < n && target[j] == '_')
//                 j++;
           
//             if(i == n || j == n)
//                 break;
//             if(start[i] != target[j])
//                 return false;
//             if(start[i] == 'L')
//                 if(i < j)
//                     return false;
//             if(start[i] == 'R')
//                 if(i > j)
//                     return false;
//             i++;
//             j++;
//         }

//         return i == n && j == n;
//     }
// };
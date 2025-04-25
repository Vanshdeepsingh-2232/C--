#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <set>
using namespace std;

class Solution
{
public:
    int minimumLength(string s)
    {
        int n = s.size();
        vector<int> chars(26, 0);
        for (int i = 0; i < n; i++)
            chars[s[i] - 'a']++;
        int sum=0;
        for(int &i:chars){
            if(i<3)
                sum+=i;
            else if(i%2==0)
                sum+=2;
            else
                sum+=1;
        }
        return sum;
    }
};

int main()
{
    string s = "abaacbcbb";
    Solution s1;
    cout << s1.minimumLength(s);
    return 0;
}
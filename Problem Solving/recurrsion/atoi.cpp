#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#define INT_MIN INT32_MIN
#define INT_MAX INT32_MAX
using namespace std;

// class Solution
// {
// public:
//     int myAtoi(string s)
//     {
//         long long result = 0;
//         string str = "";
//         string sign = "";
//         bool first = false;
//         for (int i = 0; i < s.size(); i++)
//         {
//             if (s[i] == ' ' || s[i] == '-' || s[i] == '+')
//                 continue;
//             if ((s[i] - '0' >= 0) && (s[i] - '0' <= 9))
//             {
//                 str += s[i];
//                 if (i > 0 && s[i - 1] == '-')
//                     sign += '-';
//                 if (!isdigit(s[i + 1]))
//                     break;
//                 //continue;
//             }
//             if (!isdigit(s[i]))
//                 break;
//         }

//         for (int i = 0; i < str.size(); i++)
//         {
//             result = (result * 10) + str[i] - '0';
//         }
//         if (sign[0] == '-')
//             result = 0 - result;
//         if (result < INT32_MIN)
//             return INT32_MIN;
//         if (result > INT32_MAX)
//             return INT32_MAX;

//         return (int)result;
//     }
// };
class Solution {
public:
    int myAtoi(string s)
    {
        long long ans=0;
        int neg=1;
        bool flag=false;
        for(int i=0;i<s.length();i++)
        {
            if(flag==false && (s[i]==' ' || s[i]=='0'))
            {
                if(s[i]=='0')
                {
                    flag=true;
                }
                continue;
            }
            if(flag==false && (s[i]=='+' || s[i]=='-'))
            {
                if(s[i]=='-')
                {
                    neg=-1;
                }
                flag=true;
            }
            else if(!(s[i]>='0' && s[i]<='9'))
            {
                break;
            }
            else
            {
                flag=true;
                ans*=10;
                ans+=((s[i]-'0')*neg);
                if(ans<INT_MIN)
                {
                    return INT_MIN;
                }
                else if(ans>INT_MAX)
                {
                    return INT_MAX;
                }
            }
        }
        return ans;
    }
};

int main()
{
    string s1 = "42";
    string s2 = "+-42";
    string s3 = " +42ab2232";
    string s4 = "0-1";
    string s5 = "what the hell12345678";
    Solution S1;
    cout << S1.myAtoi(s2);
    return 0;
}
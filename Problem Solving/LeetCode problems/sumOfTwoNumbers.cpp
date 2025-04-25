#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int getSum(int a, int b)
    {
        while (b != 0)
        {
            int temp = (a & b) << 1;
            a = a ^ b;
            b = temp;
        }

        return a;
    }
};

int main()
{
    Solution s1;
    int a = 5, b = 15;
    cout<<s1.getSum(a, b);
    return 0;
}
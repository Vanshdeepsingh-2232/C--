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
    bool isSet(int x, int b)
    {
        return x & (1 << b);
    }

    bool setBit(int x, int b)
    {
        return x |= (1 << b);
    }

    bool UnsetBit(int x, int b)
    {
        return x &= (~(1 << b));
    }

    int minimizeXor(int num1, int num2)
    {

        int x = num1;

        int NumSetBits = __builtin_popcount(num2);
        int XsetBits = __builtin_popcount(x);

        int bit = 0;
        if (XsetBits < NumSetBits)
        {
            while (XsetBits < NumSetBits)
            {
                if (!isSet(x, bit))
                {
                    setBit(x, bit);
                    XsetBits++;
                }
                bit++;
            }
        }
        else if (XsetBits > NumSetBits)
        {
            while (XsetBits > NumSetBits)
            {
                if (isSet(x, bit))
                {
                    UnsetBit(x, bit);
                    XsetBits--;
                }
                bit++;
            }
        }
        return x;
    }
};

int main()
{

    int num1 = 3, num2 = 5;
    Solution s1;
    cout << s1.minimizeXor(num1, num2);
    return 0;
}
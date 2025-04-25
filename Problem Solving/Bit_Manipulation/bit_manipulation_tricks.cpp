#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Bits_M
{
public:
    void swap_two_numbers(int &a, int &b)
    {
        a = a ^ b;
        b = a ^ b;
        a = a ^ b;
    }

    bool checkithBit(int n, int i)
    {
        if ((n & (1 << i)) != 0)
            return true;
        else
            return false;
    }

    

};

int main()
{
    Bits_M b1;
    int a, b;
    // 1 1 0 1
    a = 13;
    b = 1;
    cout << b1.checkithBit(a, b);
    return 0;
}
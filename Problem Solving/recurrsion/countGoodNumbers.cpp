#define ll long long
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution
{
private:
    int p = 1e9 + 7;

public:
    ll powerCalc(ll x, ll n)
    {
        ll res = 1;
        // update the X with mod value if it exceeds the mod value
        x = x % p;
        if (x == 0)
            return 0;

        while (n > 0)
        {
            if (n & 1)
                res = (res * x) % p;

            n = n >> 1;
            x = (x * x) % p;
        }
        return res;
    }
    int countGoodNumbers(long long n)
    {
        ll countOdd = n / 2;
        ll countEven = n - countEven;
        ll ans = ((powerCalc(4LL, countOdd) % p * powerCalc(5LL, countEven) % p) % p);
        return (int)ans;
    }
};
int main()
{
    Solution s1;
    cout << s1.countGoodNumbers(4);
    return 0;
}
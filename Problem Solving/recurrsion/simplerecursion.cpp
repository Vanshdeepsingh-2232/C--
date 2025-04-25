#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

int numbers(int n)
{
    if (n >= 1)
    {
        cout << n;
        return numbers(n - 1);
    }
    else
        return 0;
}

void numbers2(int n)
{
    if (n <= 0)
        return;
    cout << n;
    numbers2(n - 1);
}

void name(string n, int k)
{
    if (k <= 0)
        return;

    cout << n << endl;
    name(n, k - 1);
}

int sumofN(int n)
{
    if (n <= 0)
        return 0;
    return n + sumofN(n - 1);
}

int factorialofN(int n)
{
    if (n == 0 || n == 1)
        return 1;

    return n * factorialofN(n - 1);
}

bool isPalindrome(string s, int i)
{

    if (i > s.size() / 2)
    {
        return true;
    }

    return s[i] == s[s.size() - i - 1] && isPalindrome(s, i + 1);
}

int fibonacci_series(int n)
{
    if (n == 0)
        return 0;
    else if (n == 1 || n == 2)
        return 1;

    return fibonacci_series(n - 1) + fibonacci_series(n - 2);
}

int main()
{
    // cout << numbers(10);
    // numbers2(10);
    // name("Vansh", 5);
    // cout << sumofN(3);
    // cout << factorialofN(5);
    // cout << isPalindrome("level", 0);
    // cout << fibonacci_series(100) << endl;
    return 0;
}
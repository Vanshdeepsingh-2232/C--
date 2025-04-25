#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<set>
using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        set<int> myset;
        int val,index;
        while(1){
            val=0;
            while(n){
                index=n%10;
                val+=index*index;
                n/=10;
            }
            if(val==1) return true;
            else if(myset.find(val)!=myset.end()) return  false;

            myset.insert(val);
            n=val;
        }
        return false;
    }
};
// Example 1:        
// Input: n = 19
// Output: true
// Explanation:
// 12 + 92 = 82
// 82 + 22 = 68
// 62 + 82 = 100
// 12 + 02 + 02 = 1
// Example 2:
// Input: n = 2
// Output: false

int main(){
    Solution s1;
    int digit=19;
    cout<<s1.isHappy(digit);
    
  return 0;
}



/* ANALIZE THIS CODE ALSO 
class Solution {
public:
    using Cache = std::unordered_set<int>;

    bool isHappy(int n) {
        Cache cache;
        while (n != 1 && try_insert(cache, n)) {
            n = sumOfSquaredDigits(n);
        }
        return n == 1;
    }

private:
    static int sumOfSquaredDigits(int n) {
        int sum = 0;
        while (n != 0) {
            int digit = n % 10;
            sum += digit * digit;
            n /= 10;
        }
        return sum;
    }

    static bool try_insert(Cache& cache, int n) {
        auto [_, inserted] = cache.insert(n);
        return inserted;
    }
};
*/
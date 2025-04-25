#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <set>
#include <map>
using namespace std;

class Solution
{
public:
    bool isNStraightHand(vector<int> &hand, int groupSize)
    {
        int n = hand.size();
        if (n % groupSize != 0)
            return false;
        sort(hand.begin(), hand.end());
        map<int, int> Fmap;
        for (int i = 0; i < n; i++)
            Fmap[hand[i]]++;

        while (!Fmap.empty())
        {
            int curr = Fmap.begin()->first;
            for (int i = 0; i < groupSize; i++)
            {
                if (Fmap[curr + i] == 0)
                    return false;

                Fmap[curr + i]--;
                if (Fmap[curr + i] < 1)
                    Fmap.erase(curr + i);
            }
        }
        return true;
    }
};

int main()
{
    vector<int> hand = {1, 2, 3, 6, 2, 3, 4, 7, 8};
    // 1,2,2,3,3,4,6,7,8
    int groupSize = 3;
    Solution s1;
    cout << s1.isNStraightHand(hand, groupSize);

    return 0;
}
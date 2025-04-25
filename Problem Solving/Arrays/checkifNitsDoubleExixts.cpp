#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    bool checkIfExist(vector<int> &arr)
    {
        bool ans = false;
        unordered_map<double, int> map;
        for (int i = 0; i < arr.size(); i++)
        {
            map[arr[i]] = 0;
        }

        for (auto &i : map)
        {
            cout << i.first << "-" << i.second << endl;
        }
        for (int i = 0; i < arr.size(); i++)
        {
            map[arr[i]] = 1;
            if (map[arr[i]] == 1 && ((map[arr[i] * 2] == 1 && arr[i] != 0) || (map[arr[i] / 2] == 1 && arr[i] % 2 == 0)))
            {
                ans = true;
                break;
            }
        }
        return ans;
    }
};

int main()
{
    // 5,11,-19,-18,19,17
    //-2,0,10,-19,4,6,-8
    Solution s1;
    vector<int> arr = {-2, 0, 10, -19, 4, 6, -8};
    cout << s1.checkIfExist(arr);
    return 0;
}
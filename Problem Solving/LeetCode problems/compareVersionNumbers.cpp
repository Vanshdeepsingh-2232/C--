#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    void printVector(const vector<string> &vec)
    {
        for (const auto &element : vec)
        {
            cout << element << " ";
        }
        cout << endl;
    }
    vector<string> splitString(const string &input)
    {
        vector<string> result;
        stringstream ss(input);
        string token;
        while (getline(ss, token, '.'))
        {
            result.push_back(token);
        }
        return result;
    }

    int compareVersion(string &version1, string &version2)
    {
        vector<string> v1 = splitString(version1);
        vector<string> v2 = splitString(version2);
        int i = 0;
        int j = 0;
        while (i < v1.size() || j < v2.size()) // Corrected condition j<v2.size() instead of j<v1.size()
        {
            int num1 = (i < v1.size()) ? stoi(v1[i]) : 0;
            int num2 = (j < v2.size()) ? stoi(v2[j]) : 0;
            if (num1 == num2)
            {
                i++;
                j++;
            }
            else if (num1 < num2)
            {
                return -1;
            }
            else if (num1 > num2)
            {
                return 1;
            }
        }
        return 0;
    }
};

//TEST CASES
// Input: version1 = "1.01", version2 = "1.001"
//  Input: version1 = "0.1", version2 = "1.1"
//  Output: -1
//  Explanation: version1's revision 0 is "0", while version2's revision 0 is "1". 0 < 1, so version1 < version2.

int main()
{
    string v1 = "1.01";
    string v2 = "1.001";

    Solution s1;
    cout << s1.compareVersion(v1, v2);

    return 0;
}
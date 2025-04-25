
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution
{

private:
    void subsets(int n, int index, int sum, vector<int> &arr, vector<int> &sumSubsets)
    {

        if (index == n)
        {
            sumSubsets.push_back(sum);
            return;
        }

        // first start picking all the elements
        subsets(n, index + 1, sum + arr[index], arr, sumSubsets);

        // Now call to not pick particular elements
        subsets(n, index + 1, sum, arr, sumSubsets);
    }

public:
    vector<int> subsetSums(vector<int> arr, int n)
    {
        vector<int> sumSubsets;
        int sum = 0;
        int index = 0;
        subsets(n, index, sum, arr, sumSubsets);
        return sumSubsets;
    }
};
int main()
{
    return 0;
}

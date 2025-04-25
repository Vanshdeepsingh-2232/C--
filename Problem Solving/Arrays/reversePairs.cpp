#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <set>
using namespace std;

class Solution
{
private:
    void merge(vector<int> &arr, int low, int mid, int high)
    {

        // REMEMBER the array is only logicaly divided not physicaly divided
        // thus in the parameters we have only one array which is the original array

        // first array low -> mid
        // second array mid+1 -> high

        vector<int> temp;
        int left = low;      // this pointer determine the starting of the first array to be merged
        int right = mid + 1; // this pointer determines the starting of the second array
        while (left <= mid && right <= high)
        {
            if (arr[left] <= arr[right])
                temp.push_back(arr[left++]);
            else
                temp.push_back(arr[right++]);
        }
        while (left <= mid)
            temp.push_back(arr[left++]);

        while (right <= high)
            temp.push_back(arr[right++]);

        for (int i = low; i <= high; i++)
            arr[i] = temp[i - low];
    }

public:
    int countPairs(vector<int> &arr, int low, int mid, int high)
    {
        int cnt = 0;
        int right = mid + 1;
        for (int i = low; i <= mid; i++)
        {
            while (right <= high && arr[i] > 2LL * arr[right])
                right++;

            cnt += (right - (mid + 1));
        }
        return cnt;
    }
    int MergeSort(vector<int> &arr, int low, int high)
    {
        int cnt = 0;
        if (low >= high)
            return cnt;

        int mid = (low + high) / 2;
        cnt += MergeSort(arr, low, mid);
        cnt += MergeSort(arr, mid + 1, high);
        cnt += countPairs(arr, low, mid, high);
        merge(arr, low, mid, high);
        return cnt;
    }
    int reversePairs(vector<int> &nums)
    {
        return MergeSort(nums, 0, nums.size() - 1);
    }
};

int main()
{

    vector<int>v;
     return 0;
}
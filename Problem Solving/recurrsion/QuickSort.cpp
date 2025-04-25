#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

int partition(vector<int> &arr, int low, int high)
{
    int pivot = arr[low];
    int i = low;
    int j = high;
    while (i < j)
    {
        while (arr[i] <= pivot && i <= high-1)
            i++;
        while (arr[j] > pivot && j >= low+1)
            j--;
        if (i < j)
            swap(arr[i], arr[j]);
    }
    swap(arr[low], arr[j]);
    return j;
}

void quickSort(vector<int> &arr, int low, int high)
{
    if (low < high)
    {
        int pivot = partition(arr, low, high);
        quickSort(arr, low, pivot - 1);
        quickSort(arr, pivot + 1, high);
    }
}

vector<int> NicelySorted(vector<int> &v)
{
    quickSort(v, 0, v.size() - 1);
    return v;
}

int main()
{
    vector<int> v = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    vector<int> ans = NicelySorted(v);
    for (auto i : ans)
        cout << i;
    return 0;
}
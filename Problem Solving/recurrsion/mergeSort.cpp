#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <random>
#include <chrono>
using namespace std;

class mergeSort
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
    void fillWithRandomNumbers(std::vector<int> &vec, int count, int min, int max)
    {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dist(min, max);
        for (int i = 0; i < count; ++i)
            vec.push_back(dist(gen));
    }

    void MergeSort(vector<int> &arr, int low, int high)
    {

        if (low >= high)
        {
            return;
        }
        int mid = (low + high) / 2;
        MergeSort(arr, low, mid);
        MergeSort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
};

int main()
{
    vector<int> v = {};
    mergeSort m1;
    m1.fillWithRandomNumbers(v, 100000000, -100, 100000000);
    // Start timing
    auto start = std::chrono::high_resolution_clock::now();
    m1.MergeSort(v, 0, v.size() - 1);
    // Stop timing
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    cout << "Time taken by function: " << duration.count()/1e+6 << " seconds" << std::endl;

    return 0;
}
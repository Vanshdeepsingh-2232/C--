#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <math.h>
using namespace std;

class Heap
{
private:
    int arr[100];
    int size = 0;

public:
    Heap()
    {
        arr[0] = -1;
    }

    void print_heap()
    {
        for (int i = 0; i <= size; i++)
        {
            cout << arr[i] << "__";
        }
        cout << endl;
    }

    void insert_at_appropriate(int idx)
    {
        if (idx <= 1)
            return;
        int parent_of_idx = idx / 2;
        if ((parent_of_idx < 1))
            return;

        if (arr[parent_of_idx] < arr[idx])
        {
            swap(arr[parent_of_idx], arr[idx]);
        }
        insert_at_appropriate(parent_of_idx);
    }
    void Heap_insert(int &value)
    {
        size += 1;
        int idx = size;
        arr[idx] = value;
        insert_at_appropriate(idx);
    }

    void heapify(vector<int> &arr, int &i)
    {

        int n = arr.size();

        int largest = i;
        int left_child = 2 * i;
        int right_child = 2 * i + 1;

        if (left_child < n && arr[left_child] > arr[largest])
        {
            largest = left_child;
        }
        if (right_child < n && arr[right_child] > arr[largest])
        {
            largest = right_child;
        }

        if (largest != i)
        {
            swap(arr[largest], arr[i]);
            heapify(arr, largest);
        }
    }

    void del_properly(int node_idx)
    {
        int node_left_child = 2 * node_idx;
        int node_right_child = 2 * node_idx + 1;

        if (node_left_child < size && arr[node_idx] < arr[node_left_child])
        {
            swap(arr[node_idx], arr[node_left_child]);
            del_properly(node_left_child);
        }
        if (node_right_child < size && arr[node_idx] < arr[node_right_child])
        {
            swap(arr[node_idx], arr[node_right_child]);
            del_properly(node_right_child);
        }

        else
        {
            return;
        }
    }
    int heap_deletion()
    {
        int deleted = 0;
        if (size >= 1)
        {
            deleted = arr[1];
            arr[1] = arr[size--];
            del_properly(1);
        }
        return deleted;
    }

    vector<int> heap_sort(vector<int> &arr1)
    {
        vector<int> answer(arr1.size(), 0);
        int n = arr1.size();
        for (int i = 0; i < n; i++)
        {
            heapify(arr1, i);
            answer[i] = arr1[i];
            arr1[i] = arr1[arr1.size() - 1];
        }
        for (int i = 0, j = answer.size() - 1; i < j; i++, j--)
        {
            swap(answer[i], answer[j]);
        }

        return answer;
    }

    ~Heap() {}
};

int main()
{
    Heap h1;
    vector<int> input_array = {9, 8, 7, 5, 4, 3, 2, 1};
    int n = input_array.size();
    vector<int> ans = h1.heap_sort(input_array);
    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << "__";
    }
    cout << endl;
    return 0;
}
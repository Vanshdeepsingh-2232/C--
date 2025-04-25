#include <iostream>
using namespace std;


void merge(int arr[], int left, int middle, int right) {
    int n1 = middle - left + 1;
    int n2 = right - middle;

    int leftArray[n1];
    int rightArray[n2];

    for (int i = 0; i < n1; i++) {
        leftArray[i] = arr[left + i];
    }
    for (int i = 0; i < n2; i++) {
        rightArray[i] = arr[middle + 1 + i];
    }

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (leftArray[i] <= rightArray[j]) {
            arr[k] = leftArray[i];
            i++;
        } else {
            arr[k] = rightArray[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = leftArray[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = rightArray[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int middle = left + (right - left) / 2;
        mergeSort(arr, left, middle);
        mergeSort(arr, middle + 1, right);
        merge(arr, left, middle, right);
    }
}

int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int arrSize = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    for (int i = 0; i < arrSize; i++) {
        std::cout << arr[i] << " ";
    }

    mergeSort(arr, 0, arrSize - 1);

    cout << "\nSorted array: ";
    for (int i = 0; i < arrSize; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}

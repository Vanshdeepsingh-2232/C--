#include <iostream>
#include <cstdlib>
#include <ctime>

int getRandomIntInRange(int min, int max) {
    return min + rand() % (max - min + 1);
}


int partition(int arr[], int start, int end)
{
 
    int pivot = arr[start];
 
    int count = 0;
    for (int i = start + 1; i <= end; i++) {
        if (arr[i] <= pivot)
            count++;
    }
 
    // Giving pivot element its correct position
    int pivotIndex = start + count;
    std::swap(arr[pivotIndex], arr[start]);
 
    // Sorting left and right parts of the pivot element
    int i = start, j = end;
 
    while (i < pivotIndex && j > pivotIndex) {
 
        while (arr[i] <= pivot) {
            i++;
        }
 
        while (arr[j] > pivot) {
            j--;
        }
 
        if (i < pivotIndex && j > pivotIndex) {
            std::swap(arr[i++], arr[j--]);
        }
    }
 
    return pivotIndex;
}
 
void quickSort(int arr[], int start, int end)
{
 
    // base case
    if (start >= end)
        return;
 
    // partitioning the array
    int p = partition(arr, start, end);
 
    // Sorting the left part
    quickSort(arr, start, p - 1);
 
    // Sorting the right part
    quickSort(arr, p + 1, end);
}

int main() {
    clock_t start = clock();
    // Seed the random number generator with the current time
    srand(static_cast<unsigned>(time(nullptr)));

    int minRange = 1;
    int maxRange = 1000000000;

    // Array seeding with random elements
    int arr[100000];
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
        int randomInt = getRandomIntInRange(minRange, maxRange);
        arr[i] = randomInt;
    }
    
    int n=sizeof(arr) / sizeof(arr[0]);
    
    
    quickSort(arr, 0, n - 1);

    clock_t end = clock();
    double elapsed_time = double(end - start) / CLOCKS_PER_SEC;
    
    std::cout<<"After sorting"<<std::endl;
    

    std::cout<<"The time this code takes is = "<<elapsed_time<<std::endl;

    return 0;
}

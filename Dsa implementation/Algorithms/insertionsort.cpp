#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;


int getRandomIntInRange(int min, int max) {
    return min + rand() % (max - min + 1);
}

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
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
    
    int n = sizeof(arr) / sizeof(arr[0]);

    // std::cout << "Original array: "<<endl;
    // for (int i = 0; i < n; i++) {
    //     std::cout << arr[i] << " ";
    // }

    insertionSort(arr, n);

    // std::cout << "\nSorted array: "<<endl;
    // for (int i = 0; i < n; i++) {
    //     std::cout << arr[i] << " ";
    // }


    clock_t end = clock();
    double elapsed_time = double(end - start) / CLOCKS_PER_SEC;
    

    std::cout<<"After sorting"<<std::endl;
    std::cout<<"The time this code takes is = "<<elapsed_time<<std::endl;


    return 0;
}

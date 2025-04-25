#include <iostream>
#include <vector>

using namespace std;

void generateSubArrays(const vector<int>& arr, int k) {
    int n = arr.size();

    // Ensure the window size is valid
    if (k > n) {
        cout << "Window size is larger than array size." << endl;
        return;
    }

    
    for (int i = 0; i <= n - k; i++) {
        cout << "Subarray: ";
        // Generate subarray of size k starting from index i
        for (int j = i; j < i + k; j++) {
            cout << arr[j] << " ";
        }
        cout << endl;
    }
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 6};
    int k = 3; // Size of the sliding window

    generateSubArrays(arr, k);

    return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>

void generateCombinations(std::vector<int>& digits, std::vector<int>& current, int k, int& count) {
    if (k == 0) {
        // Print the current combination
        for (int digit : current) {
            std::cout << digit << " ";
        }
        std::cout << std::endl;
        count++;
        return;
    }

    for (size_t i = 0; i < digits.size(); ++i) {
        // Avoid using the same digit in the current combination
        if (std::find(current.begin(), current.end(), digits[i]) == current.end()) {
            current.push_back(digits[i]);
            generateCombinations(digits, current, k - 1, count);
            current.pop_back();
        }
    }
}

int main() {
    std::vector<int> digits = {1, 2, 3, 4};
    std::vector<int> current;

    std::cout << "All combinations without repetition:" << std::endl;

    // Generate combinations with 1, 2, 3, and 4 digits
    for (int k = 1; k <= 4; ++k) {
        int count = 0;
        std::cout << "Combinations of " << k << " digits:" << std::endl;
        generateCombinations(digits, current, k, count);
        std::cout << "Total combinations: " << count << std::endl;
    }

    return 0;
}

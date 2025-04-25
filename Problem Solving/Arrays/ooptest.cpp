#include <iostream>

int main() {
    try {
        int numerator, denominator;
        double result;

        // Get user input for numerator and denominator
        std::cout << "Enter the numerator: ";
        std::cin >> numerator;
        std::cout << "Enter the denominator: ";
        std::cin >> denominator;

        // Check for division by zero
        if (denominator == 0) {
            throw "Division by zero is not allowed.";
        }

        // Perform division
        result = static_cast<double>(numerator) / denominator;

        // Output the result
        std::cout << "Result: " << result << std::endl;
    } catch (const char* errorMessage) {
        std::cerr << "Error: " << errorMessage << std::endl;
    }

    return 0;
}

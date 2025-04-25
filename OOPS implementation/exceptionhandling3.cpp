#include <iostream>
#include <stdexcept>

void innerFunction() {
    try {
        // Some code that might throw an exception
        throw std::runtime_error("An error occurred in innerFunction");
    } catch (const std::exception& e) {
        // Handle the exception at this level
        std::cerr << "Caught exception in innerFunction: " << e.what() << std::endl;

        // Rethrow the same exception to let it propagate up the call stack
        throw;
    }
}

void middleFunction() {
    try {
        innerFunction();
    } catch (const std::exception& e) {
        // Handle the exception at this level
        std::cerr << "Caught exception in middleFunction: " << e.what() << std::endl;

        // Rethrow the same exception to let it propagate up the call stack
        throw;
    }
}

void outerFunction() {
    try {
        middleFunction();
    } catch (const std::exception& e) {
        // Handle the exception at this level
        std::cerr << "Caught exception in outerFunction: " << e.what() << std::endl;
    }
}

int main() {
    try {
        outerFunction();
    } catch (const std::exception& e) {
        // Handle the exception at the top level
        std::cerr << "Caught exception in main: " << e.what() << std::endl;
    }

    return 0;
}

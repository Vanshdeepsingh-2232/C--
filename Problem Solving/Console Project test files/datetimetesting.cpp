#include <iostream>
#include <chrono>
#include <ctime>
#include <iomanip>
#include <sstream>

int main() {
    // Get the current time point
    auto currentTimePoint = std::chrono::system_clock::now();

    // Convert the current time point to a time_t object
    std::time_t currentTime = std::chrono::system_clock::to_time_t(currentTimePoint);

    // Print the current time using ctime
    std::cout << "Current time: " << std::ctime(&currentTime);

    // Format the current time using tm and strftime
    std::tm* timeInfo = std::localtime(&currentTime);
    char buffer[80]; // Buffer to hold the formatted time
    std::strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", timeInfo);
    std::cout << "Formatted time: " << buffer << std::endl;

    // You can also work with durations (e.g., to represent a duration of 2 hours)
    std::chrono::hours twoHours(2);
    auto futureTimePoint = currentTimePoint + twoHours;

    // Convert the future time point to a time_t object
    std::time_t futureTime = std::chrono::system_clock::to_time_t(futureTimePoint);

    // Format the future time using tm and strftime
    std::tm* futureTimeInfo = std::localtime(&futureTime);
    std::strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", futureTimeInfo);
    std::cout << "Future time: " << buffer << std::endl;

    return 0;
}

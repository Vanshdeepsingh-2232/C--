#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Structure to represent items
struct Item {
    int value;
    int weight;
};

// Function to compare items based on their value per unit weight
bool compare(Item a, Item b) {
    double ratio_a = (double)a.value / a.weight;
    double ratio_b = (double)b.value / b.weight;
    return ratio_a > ratio_b;
}

// Function to solve fractional knapsack problem
double fractionalKnapsack(int capacity, vector<Item>& items) {
    // Sort items based on their value per unit weight
    sort(items.begin(), items.end(), compare);

    double totalValue = 0.0; // Total value of items taken
    int currentWeight = 0;   // Current weight in knapsack

    // Loop through each item
    for (auto& item : items) {
        // If adding the entire item won't exceed the capacity, add it fully
        if (currentWeight + item.weight <= capacity) {
            currentWeight += item.weight;
            totalValue += item.value;
        } else {
            // Otherwise, add a fraction of the item to fill the capacity
            int remainingCapacity = capacity - currentWeight;
            totalValue += (double)item.value / item.weight * remainingCapacity;
            break;
        }
    }
    return totalValue;
}

int main() {
    vector<Item> items = {{60, 10}, {100, 20}, {120, 30}};
    int capacity = 50;

    double maxValue = fractionalKnapsack(capacity, items);
    cout << "Maximum value in knapsack = " << maxValue << endl;

    return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#include<unordered_map>

// Given an unsorted array of integers nums,
// return the length of the longest consecutive elements sequence.
// You must write an algorithm that runs in O(n) time.
// Example 1:

// Input: nums = [100,4,200,1,3,2]
// Output: 4
// Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
// Example 2:

// Input: nums = [0,3,7,2,5,8,4,6,0,1]
// Output: 9


int longestConsecutive(std::vector<int>& nums) {
    if (nums.empty()) {
        return 0;
    }

    // Find the minimum and maximum elements in the array
    int min_val = *std::min_element(nums.begin(), nums.end());
    int max_val = *std::max_element(nums.begin(), nums.end());

    // Create a vector for marking occurrences
    std::vector<int> mark(max_val - min_val + 1, 0);

    // Mark the occurrences of elements
    for (int num : nums) {
        mark[num - min_val] = 1;
    }

    // Find the longest streak of consecutive ones
    int longest_streak = 0;
    int current_streak = 0;

    for (int i = 0; i < mark.size(); ++i) {
        if (mark[i] == 1) {
            current_streak++;
            longest_streak = std::max(longest_streak, current_streak);
        } else {
            current_streak = 0;
        }
    }

    return longest_streak;
}

int main() {
    std::vector<int> nums = {100, 4, 200, 1, 3, 2};
    std::cout << "Longest consecutive sequence length: " << longestConsecutive(nums) << std::endl;
    return 0;
}

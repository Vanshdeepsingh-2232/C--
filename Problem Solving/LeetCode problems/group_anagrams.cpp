
#include<iostream>
#include<vector>
#include<string>
#include<algorithm> // Need this for sorting strings
#include<unordered_map> // Need this for using unordered_map
using namespace std;

class Solution {
public:
    
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> hash_map; // Use unordered_map to group anagrams
        
        // Iterate through each string in the input vector
        for(const string& s : strs) {
            string sorted_s = s; // Make a copy of the string
            sort(sorted_s.begin(), sorted_s.end()); // Sort the characters of the string
            
            // Add the sorted string to the hash_map as key and the original string as value
            hash_map[sorted_s].push_back(s);
        }
        
        // Convert hash_map values (vector<string>) to vector<vector<string>>
        vector<vector<string>> result;
        for(auto& pair : hash_map) {
            result.push_back(pair.second);
        }
        
        return result;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> hash_map; // Use unordered_map to group anagrams
        
        // Iterate through each string in the input vector
        for(const string& s : strs) {
            // Count the frequency of each character in the string
            string key = countFrequency(s);
            
            // Add the frequency count as key to the hash_map and the original string as value
            hash_map[key].push_back(s);
        }
        
        // Convert hash_map values (vector<string>) to vector<vector<string>>
        vector<vector<string>> result;
        for(const auto& pair : hash_map) {
            result.push_back(pair.second);
        }
        
        return result;
    }
    
    // Helper function to count the frequency of each character in a string
    string countFrequency(const string& s) {
        // Initialize an array to store the count of each character (assuming ASCII characters)
        int count[26] = {0};
        
        // Count the frequency of each character in the string
        for(char c : s) {
            count[c - 'a']++;
        }
        
        // Construct a key string based on the frequency count
        string key = "";
        for(int i = 0; i < 26; i++) {
            if(count[i] > 0) {
                key += string(1, 'a' + i) + to_string(count[i]);
            }
        }
        
        return key;
    }
};

int main(){
    Solution s1;
    vector<string> strs={"eat","tea","tan","ate","nat","bat","","duh","ill"};
    vector<vector<string>> result = s1.groupAnagrams(strs);
    
    // Print the result
    for(const auto& group : result) {
        for(const string& word : group) {
            cout << word << " ";
        }
        cout << endl;
    }

  return 0;
}

#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;

#include <iostream>
#include <vector>

class TrieNode {
public:
    vector<TrieNode*> children;
    bool isEndOfWord;

    TrieNode() : children(26, nullptr), isEndOfWord(false) {}
};

class Trie {
private:
    TrieNode* root;

public:
    Trie() {
        root = new TrieNode();
    }

    // Insert a word into the Trie
    void insert(const string& word) {
        TrieNode* node = root;
        for (char c : word) {
            int index = c - 'a';
            if (node->children[index] == nullptr) {
                node->children[index] = new TrieNode();
            }
            node = node->children[index];
        }
        node->isEndOfWord = true;
    }

    // Search for a word in the Trie
    bool search(const string& word) const {
        TrieNode* node = root;
        for (char c : word) {
            int index = c - 'a';
            if (node->children[index] == nullptr) {
                return false;
            }
            node = node->children[index];
        }
        return node != nullptr && node->isEndOfWord;
    }

    // Check if any word in the Trie starts with the given prefix
    bool startsWith(const string& prefix) const {
        TrieNode* node = root;
        for (char c : prefix) {
            int index = c - 'a';
            if (node->children[index] == nullptr) {
                return false;
            }
            node = node->children[index];
        }
        return true;
    }

    // Destructor to free allocated memory
    ~Trie() {
        deleteTrie(root);
    }

private:
    void deleteTrie(TrieNode* node) {
        if (node == nullptr) return;
        for (auto child : node->children) {
            deleteTrie(child);
        }
        delete node;
    }
};



class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        Trie trie;
        for (int i = 0; i < wordDict.size(); i++)
        {
            trie.insert(wordDict[i]);
        }
        int i=0,j=s.length()-1;
        
        while (j < s.length())
        {
            
        }
         
    }
};


// Example 1:
// Input: s = "catsanddog", wordDict = ["cat","cats","and","sand","dog"]
// Output: ["cats and dog","cat sand dog"]

// Example 2:
// Input: s = "pineapplepenapple", wordDict = ["apple","pen","applepen","pine","pineapple"]
// Output: ["pine apple pen apple","pineapple pen apple","pine applepen apple"]
// Explanation: Note that you are allowed to reuse a dictionary word.

// Example 3:
// Input: s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
// Output: []



int main(){

  return 0;
}
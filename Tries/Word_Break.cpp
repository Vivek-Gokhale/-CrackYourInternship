#include<bits/stdc++.h>
using namespace std;
class TrieNode {
public:
    char character;
    TrieNode* children[26];
    bool isEndOfWord;

    TrieNode(char c) {
        character = c;
        for (int i = 0; i < 26; i++) children[i] = nullptr;
        isEndOfWord = false;
    }
};

class Solution {
public:
    TrieNode* root;

    Solution() {
        root = new TrieNode('\0');
    }

    void insertWord(TrieNode* root, const string& word) {
        TrieNode* currentNode = root;
        for (char c : word) {
            int index = c - 'a';
            if (currentNode->children[index] == nullptr) {
                currentNode->children[index] = new TrieNode(c);
            }
            currentNode = currentNode->children[index];
        }
        currentNode->isEndOfWord = true;
    }

    bool canSegmentString(TrieNode* root, const string& s, int start, vector<int>& memo) {
        if (start == s.size()) return true; 

        if (memo[start] != -1) return memo[start]; 

        TrieNode* currentNode = root;
        for (int i = start; i < s.size(); ++i) {
            int index = s[i] - 'a';
            if (currentNode->children[index] == nullptr) {
                memo[start] = 0;
                return false; 
            }
            currentNode = currentNode->children[index];
            if (currentNode->isEndOfWord && canSegmentString(root, s, i + 1, memo)) {
                memo[start] = 1;
                return true;
            }
        }
        memo[start] = 0; 
        return false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        for (const string& word : wordDict) {
            insertWord(root, word); 
        }
        vector<int> memo(s.size(), -1);
        return canSegmentString(root, s, 0, memo);
    }
};
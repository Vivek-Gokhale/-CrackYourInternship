#include<bits/stdc++.h>
using namespace std;
class TrieNode
{
    public:
    vector<TrieNode*> children;
    bool isTerminal;
    TrieNode()
    {
        children.resize(26, nullptr);
        isTerminal = false;
    }
};
class WordDictionary {
public:
    TrieNode *root;
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode *child = root;
        for(int i=0; i<word.size(); i++)
        {
            int index = word[i] - 'a';
            if(child->children[index] == NULL)
            {
                child->children[index] = new TrieNode();
            }
                child = child->children[index];
        }
        child->isTerminal = true;
    }
    bool searchHelper(string word, TrieNode *root)
    {
        TrieNode *child = root;
        if(word.size() == 0) return child->isTerminal;
        int index = word[0] - 'a';
        if(word[0] == '.')
        {
            for(int i=0; i<26; i++)
            {
                if(child->children[i])
                {
                    bool srh = searchHelper(word.substr(1), child->children[i]);
                    if(srh == true) return true;
                }
            }
            return false;
        }
        else
        {
            if(!child->children[index])return false;
            return searchHelper(word.substr(1), child->children[index]);
        }
    }
    bool search(string word) {
     return searchHelper(word, root); 
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
// #include <bits/stdc++.h>
// using namespace std;
// class Solution{
// public:
//     // Structure for Trie Node
//     struct TrieNode{
//     	unordered_map<char,TrieNode*> child;
//     	bool isLast;
//     	TrieNode(){
//     		for (char i = 'a'; i <= 'z'; i++)
//     			child[i] = NULL;
//     		isLast = false;
//     	}
//     };
//     TrieNode *root = NULL;
    
//     // Function to insert a string into the Trie
//     void insert(string s){
//     	int len = s.length();
//     	TrieNode *itr = root;
//     	for (int i = 0; i < len; i++){
//     		TrieNode *nextNode = itr->child[s[i]];
//     		if (nextNode == NULL){
//     			nextNode = new TrieNode();
//     			itr->child[s[i]] = nextNode;
//     		}
//     		itr = nextNode;
//     		if (i == len - 1)
//     			itr->isLast = true;
//     	}
//     }
    
//     // Function to insert contact strings into the Trie
//     void insertIntoTrie(string s[],int n){
//     	root = new TrieNode();
//     	for (int i = 0; i < n; i++)
//     		// insert(s[i]);
//     }
    
//     // Utility function to display contacts starting from given prefix
//     void displayContactsUtil(TrieNode *curNode, string prefix, 
//                             vector<string> &vec){
//     	if (curNode->isLast)
//     		    vec.push_back(prefix);
//     	for (char i = 'a'; i <= 'z'; i++){
//     		TrieNode *nextNode = curNode->child[i];
//     		if (nextNode != NULL)
//     			displayContactsUtil(nextNode, prefix + (char)i, vec);
//     	}
//     }
    
//     // Main function to display contacts for a given prefix
//     vector<vector<string>> displayContacts(int n, string contact[], string s)
//     {
//     	// Insert contact strings into the Trie
//     	insertIntoTrie(contact, n);
//     	TrieNode *prevNode = root;
//         vector<vector<string>> res;
//     	string prefix = "";
//     	int len = s.length();
//     	int i;
    	
//     	// Iterate through the given string prefix
//     	for(i = 0; i < len; i++){
//     		vector<string> v;
//     		prefix += (char)s[i];
//     		char lastChar = prefix[i];
//     		TrieNode *curNode = prevNode->child[lastChar];
    		
//     		// If no more contacts can be found, add 0 to the result vector
//     		if (curNode == NULL){
//     			v.push_back("0");
//     			res.push_back(v);
//     			i++;
//     			break;
//     		}
//     		displayContactsUtil(curNode, prefix, v);
//     		prevNode = curNode;
//     		res.push_back(v);
//     	}
    	
//     	// If there are remaining characters in the prefix, add 0 to the result vector
//     	for (; i<len; i++){
//     	    vector<string> v;
//     	    v.push_back("0");
//     	    res.push_back(v);
//     	}
    	
//     	// Return the final result vector
//     	return res;
//     }
// };
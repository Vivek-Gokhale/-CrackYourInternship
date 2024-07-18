// 121. Print all anagram together

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<string>> Anagrams(vector<string>& string_list) {
        int n = string_list.size();
        vector<vector<string>> ans;
        if (n == 0) return {{}};

        unordered_map<string, vector<string>> umap;
        vector<string> keys; // To maintain the order of first appearance of keys

        for (const auto& s : string_list) {
            string sorted_str = s;
            sort(sorted_str.begin(), sorted_str.end());
            if (umap.find(sorted_str) == umap.end()) {
                keys.push_back(sorted_str);
            }
            umap[sorted_str].push_back(s);
        }

        for (const auto& key : keys) {
            ans.push_back(umap[key]);
        }

        return ans;
    }
};
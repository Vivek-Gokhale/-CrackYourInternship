// 121.  Group Anagrams
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
    int n = strs.size();
    vector<vector<string>> ans;
    if(n == 0)return {{""}};
    unordered_map<string, vector<string>> umap;
    for(auto s : strs)
    {
        string temp = s;
        sort(s.begin(), s.end());
        umap[s].push_back(temp);
    } 
    for(auto it : umap)
    {
        ans.push_back(it.second);
    }
    return ans;
    }
};
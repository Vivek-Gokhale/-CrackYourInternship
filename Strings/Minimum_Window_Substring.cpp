// 121.  Minimum Window Substring
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string minWindow(string s, string t) {
    
    int n = s.size();
    if(t.size() > n)return "";

    int i=0, j=0;
    int minWindowSize = INT_MAX;
    int start_i = 0;
    int requiredCount = t.size();
    unordered_map<char, int> umap;
    for(auto it : t)
    {
        umap[it]++;
    }

    while(j < n)
    {
        char ch = s[j];
        if(umap[ch] > 0)
        requiredCount--;

        umap[ch]--;
        while(requiredCount == 0)
        {
            int currWindowSize = j-i+1; 
            char ch = s[i];
            if(currWindowSize < minWindowSize)
            {
                minWindowSize = currWindowSize;
                start_i = i;
            }
            umap[ch]++;
            if(umap[ch] > 0)
            requiredCount++;

            i++;
        }
        j++;

    }
    return minWindowSize == INT_MAX ? "" : s.substr(start_i, minWindowSize);

    }
};
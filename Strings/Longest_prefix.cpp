// 121.  Longest Prefix
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(), strs.end());
        string str1 = strs[0];
        string str2 = strs[strs.size()-1];
        string ans = "";
        for(int i=0; i<min(str1.size(), str2.size()); i++)
        {
            if(str1[i] != str2[i])
            return ans;
            ans += str1[i];
        }
        return ans;
    }
};
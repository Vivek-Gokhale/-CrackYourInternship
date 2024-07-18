// 121. Reverse Words in String

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string reverseWords(string s) {
        string ans = "";
        stringstream ss(s);
        string word;
        while (ss >> word) { // Use operator>> to handle multiple spaces
            if (!ans.empty()) {
                ans = " " + ans; // Add space before the current ans if it's not empty
            }
            ans = word + ans;
        }
        return ans;
    }
};
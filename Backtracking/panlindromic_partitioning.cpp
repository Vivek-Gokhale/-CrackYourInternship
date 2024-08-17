#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isPalindrome(string s, int left, int right) {
        while (left <= right) {
            if (s[left] != s[right])
                return false;
            left++;
            right--;
        }
        return true;
    }

    void Helper(string s, int idx, vector<string> &temp, vector<vector<string>> &ans) {
        if (idx == s.size()) {
            ans.push_back(temp);
            return;
        }
        for (int i = idx + 1; i <= s.size(); i++) {
            if (isPalindrome(s, idx, i - 1)) { // Adjust right index for isPalindrome
                temp.push_back(s.substr(idx, i - idx)); // Correct substring calculation
                Helper(s, i, temp, ans); // Correct index increment
                temp.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<string> temp;
        vector<vector<string>> ans;
        Helper(s, 0, temp, ans);
        return ans;
    }
};
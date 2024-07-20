// 121. Convert To Column Excel number

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string convertToTitle(int columnNumber) {
        string ans = "";
        while(columnNumber) {
            columnNumber--; // Decrement to make it 0-based
            int rem = columnNumber % 26;
            char ch = rem + 'A'; // Convert to corresponding character
            ans = ch + ans;
            columnNumber = columnNumber / 26;
        }
        return ans;
    }
};

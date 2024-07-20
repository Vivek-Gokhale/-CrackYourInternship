// 121. Add Binary

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string addBinary(string a, string b) {
       int i = a.size() - 1;
       int j = b.size() - 1;
       int carry = 0;
       string ans =  "";
       while (i >= 0 || j >= 0 || carry > 0) {
            int digitOne = i >= 0 ? (a[i] - '0') : 0;
            int digitTwo = j >= 0 ? (b[j] - '0') : 0;
            i--;
            j--;
            int sum = digitOne + digitTwo + carry;
            carry = sum / 2;
            int currentDigit = sum % 2;
            ans = to_string(currentDigit) + ans;
       }
       return ans;
    }
};

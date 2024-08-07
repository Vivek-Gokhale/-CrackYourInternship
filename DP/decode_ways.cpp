#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int Helper(int idx, string &s, vector<int> &memo) {
        if (idx >= s.size()) return 1;
        if (s[idx] == '0') return 0;
        if (memo[idx] != -1) return memo[idx];

        int op1 = Helper(idx + 1, s, memo);
        int op2 = 0;
        
        if (idx + 1 < s.size() && (s[idx] == '1' || (s[idx] == '2' && s[idx+1] <= '6'))) {
            op2 = Helper(idx + 2, s, memo);
        }

        return memo[idx] = op1 + op2;
    }

    int numDecodings(string s) {
        if (s.empty()) return 0;
        vector<int> memo(s.size(), -1);
        return Helper(0, s, memo);
    }
};

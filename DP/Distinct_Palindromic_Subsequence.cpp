#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int countPalindromicSubsequences(std::string s) {
        const int MOD = 1e9 + 7;
        std::unordered_map<char, int> mp;
        int n = s.size();
        std::vector<int> next(n), prev(n);
        
        // Fill the prev array
        for (int i = 0; i < n; ++i) {
            if (mp.find(s[i]) != mp.end()) {
                prev[i] = mp[s[i]];
            } else {
                prev[i] = -1;
            }
            mp[s[i]] = i;
        }
        
        mp.clear();
        
        // Fill the next array
        for (int i = n - 1; i >= 0; --i) {
            if (mp.find(s[i]) != mp.end()) {
                next[i] = mp[s[i]];
            } else {
                next[i] = -1;
            }
            mp[s[i]] = i;
        }
        
        std::vector<std::vector<long long>> dp(n, std::vector<long long>(n, 0));
        
        for (int g = 0; g < n; ++g) {
            for (int i = 0, j = g; j < n; ++i, ++j) {
                if (g == 0) {
                    dp[i][j] = 1;
                } else if (g == 1) {
                    dp[i][j] = 2;
                } else {
                    if (s[i] != s[j]) {
                        dp[i][j] = (dp[i + 1][j] + dp[i][j - 1] - dp[i + 1][j - 1] + MOD) % MOD;
                    } else {
                        int n = next[i];
                        int p = prev[j];
                        if (n > p) {
                            dp[i][j] = (2 * dp[i + 1][j - 1] + 2) % MOD;
                        } else if (n == p) {
                            dp[i][j] = (2 * dp[i + 1][j - 1] + 1) % MOD;
                        } else {
                            dp[i][j] = (2 * dp[i + 1][j - 1] - dp[n + 1][p - 1] + MOD) % MOD;
                        }
                    }
                }
            }
        }
        
        return dp[0][n - 1];
    }
};
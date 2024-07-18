// 121. Distinct Subsequence

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    // int dp[1001][1001];
    // int Helper(int i, string s, int j, string t){
    //     if(j == 0)return 1;
    //     if(i == 0)return 0;
    //     if(dp[i][j] != -1)return dp[i][j];
        
    //     if(s[i-1] == t[j-1])
    //     {
    //         int op1 = Helper(i-1, s, j-1, t);
    //         int op2 = Helper(i-1, s, j, t);
    //         return dp[i][j] = op1+op2;
    //     }
    //     else
    //     {
    //         return dp[i][j] = Helper(i-1,s, j, t);
    //     }
    // }
    int numDistinct(string s, string t) {
    //   int n = s.size();
    //     int m = t.size();
    //     vector<vector<long long>> dp(n+1, vector<long long>(m+1, 0));

    //     // Initialize the dp array for the base cases
    //     for(int i = 0; i <= n; ++i)
    //         dp[i][0] = 1;  // There's one way to match an empty t in any prefix of s

    //     for(int i = 1; i <= n; ++i) {
    //         for(int j = 1; j <= m; ++j) {
    //             if(s[i-1] == t[j-1]) {
    //                 dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
    //             } else {
    //                 dp[i][j] = dp[i-1][j];
    //             }
    //         }
    //     }

    //     return (int) dp[n][m];

     int n = s.size();
        int m = t.size();
        std::vector<double> prev(m + 1, 0);

        // Base case: There's one way to match an empty t in any prefix of s
        prev[0] = 1;

        for (int i = 1; i <= n; ++i) {
            std::vector<double> curr(m + 1, 0);
            curr[0] = 1; // Initializing current row for the base case

            for (int j = 1; j <= m; ++j) {
                if (s[i - 1] == t[j - 1]) {
                    curr[j] = prev[j - 1] + prev[j];
                } else {
                    curr[j] = prev[j];
                }
            }

            prev = curr;
        }

        return (int) prev[m];
    }
};
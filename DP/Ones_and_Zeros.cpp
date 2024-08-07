#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    // int dp[600][101][101];
    // int Helper(vector<pair<int, int>> &vec, int idx, int m, int n)
    // {
    //     if(idx < 0)return 0;
    //     if(dp[idx][m][n] != -1)return dp[idx][m][n];
    //     int take = 0;
    //     int non_take = 0;
    //     non_take = Helper(vec, idx-1, m, n);
    //     if(vec[idx].first <= m && vec[idx].second <= n)
    //     {
    //         take = 1 + Helper(vec, idx-1, m-vec[idx].first, n-vec[idx].second);
    //     }
    //     return dp[idx][m][n] = max(take, non_take);
    // }
       int findMaxForm(vector<string>& strs, int m, int n) {
        vector<pair<int, int>> vec;
        for (auto it : strs) {
            int oneCnt = 0;
            int zeroCnt = 0;
            for (auto digit : it) {
                if (digit == '0')
                    zeroCnt++;
                else 
                    oneCnt++;
            }
            vec.push_back({zeroCnt, oneCnt});
        }
        
        vector<vector<vector<int>>> dp(vec.size() + 1, vector<vector<int>>(m + 1, vector<int>(n + 1, 0)));

        for (int i = 1; i <= vec.size(); ++i) {
            int zeros = vec[i-1].first;
            int ones = vec[i-1].second;
            for (int j = 0; j <= m; ++j) {
                for (int k = 0; k <= n; ++k) {
                    dp[i][j][k] = dp[i-1][j][k]; // not taking the current string
                    if (j >= zeros && k >= ones) {
                        dp[i][j][k] = max(dp[i][j][k], dp[i-1][j-zeros][k-ones] + 1); // taking the current string
                    }
                }
            }
        }
        
        return dp[vec.size()][m][n];
    }
};
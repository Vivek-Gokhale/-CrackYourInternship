#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    // int dp[100][100];
    // int Helper(int i, int j)
    // {
    //     if(i == 0 && j == 0)return dp[i][j] = 1;
    //     if(i < 0 || j < 0)return 0;
    //     if(dp[i][j] != -1)return dp[i][j];
    //     int top = Helper(i-1, j);
    //     int left = Helper(i, j-1);
    //     return dp[i][j] = (top + left);
    // }
    int uniquePaths(int m, int n) {
        // memset(dp, -1, sizeof(dp));
        // vector<vector<int>> dp(m, vector<int>(n,0));
        // dp[0][0] = 1;
        // for(int i=0; i<m; i++)
        // {
        //     for(int j=0; j<n; j++)
        //     {
        //         if(i == 0 && j == 0)continue;
        //         int top = i-1 >= 0 ? dp[i-1][j] : 0;
        //         int left = j-1 >= 0 ? dp[i][j-1] : 0;
        //         dp[i][j] = top + left;
        //     }
        // }
        // // return Helper(m-1, n-1);
        // return dp[m-1][n-1];
 vector<int> prev(n, 0);
    
    for(int i = 0; i < m; i++) {
        vector<int> temp(n, 0);
        for(int j = 0; j < n; j++) {
            if(i == 0 && j == 0) {
                temp[j] = 1; // Starting point
            } else {
                int top = (i > 0) ? prev[j] : 0;
                int left = (j > 0) ? temp[j-1] : 0;
                temp[j] = top + left;
            }
        }
        prev = temp;
    }
    
    return prev[n-1];
    }
};
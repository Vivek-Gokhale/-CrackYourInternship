#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int dp[200][200];
    int Helper(int i, int j, vector<vector<int>>& grid)
    {
    
        if(i == 0 && j == 0)return grid[i][j];
        if(i < 0 || j < 0)return 1e9;
        if(dp[i][j] != -1)return dp[i][j];
        int op1 = grid[i][j] + Helper(i-1, j, grid);
        int op2 = grid[i][j] + Helper(i, j-1, grid);
        return dp[i][j] = min(op1, op2);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        // memset(dp, -1, sizeof(dp));
        // return Helper(m-1, n-1, grid);

       /* vector<vector<int>> dp(m, vector<int>(n, 1e9));
        dp[0][0] = grid[0][0];
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(i == 0 && j == 0)dp[i][j] = grid[0][0];
                else {
                    int op1 = i > 0 ? grid[i][j] + dp[i-1][j] : 1e9;
                    int op2 = j > 0 ? grid[i][j] + dp[i][j-1] : 1e9;
                    dp[i][j] = min(op1, op2);
                }
            }
        }
        return dp[m-1][n-1];
        */

        vector<int> prev(n, 1e9);
        
        for(int i=0; i<m; i++)
        {
            vector<int> curr(n, 1e9);
            for(int j=0; j<n; j++)
            {
                if(i == 0 && j == 0)curr[j] = grid[0][0];
                else {
                    int op1 = i > 0 ? grid[i][j] + prev[j] : 1e9;
                    int op2 = j > 0 ? grid[i][j] + curr[j-1] : 1e9;
                    curr[j] = min(op1, op2);
                }
            }
            prev = curr;
        }
        return prev[n-1];

    }
};
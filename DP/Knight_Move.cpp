#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int mod = 1e9 + 7;
    int rows[8] = {-2, -2, -1, -1, +1, +1, +2, +2};
    int cols[8] = {-1, +1, +2, -2, +2, -2, +1, -1};
    
    int Helper(int n, int i, int j, vector<vector<vector<int>>>& dp) {
        if (n == 0) return 1;
        if (i < 0 || j < 0 || i >= 4 || j >= 3) return 0;
        if (i == 3 && j == 0) return 0; // invalid '*' key
        if (i == 3 && j == 2) return 0; // invalid '#' key
        
        if (dp[n][i][j] != -1) return dp[n][i][j];
        
        int ans = 0;
        for (int k = 0; k < 8; k++) {
            int newRow = i + rows[k];
            int newCol = j + cols[k];
            // Ensure the new position is within bounds and valid
            if (newRow >= 0 && newRow < 4 && newCol >= 0 && newCol < 3 && !(newRow == 3 && (newCol == 0 || newCol == 2))) {
                ans = (ans + Helper(n - 1, newRow, newCol, dp)) % mod;
            }
        }
        return dp[n][i][j] = ans;
    }
    
    int knightDialer(int n) {
        int ans = 0;
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(4, vector<int>(3, -1)));
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 3; j++) {
                if (i == 3 && (j == 0 || j == 2)) continue; // skip invalid '*' and '#' keys
                ans = (ans + Helper(n - 1, i, j, dp)) % mod;
            }
        }
        return ans;
    }
};

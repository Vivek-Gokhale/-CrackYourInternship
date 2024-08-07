 #include <bits/stdc++.h>
using namespace std;
 int Helper(int n, int c1, int c2, int c3, vector<int>& dp) {
        if (n == 0) return 0;
        if (n < 0) return INT_MIN;
        
        if (dp[n] != -1) return dp[n];
        
        int cut1 = 1 + Helper(n - c1, c1, c2, c3, dp);
        int cut2 = 1 + Helper(n - c2, c1, c2, c3, dp);
        int cut3 = 1 + Helper(n - c3, c1, c2, c3, dp);
        
        dp[n] = max(cut1, max(cut2, cut3));
        return dp[n];
    }
    
    int maximizeTheCuts(int n, int x, int y, int z) {
        vector<int> dp(n + 1, -1);
        int result = Helper(n, x, y, z, dp);
        return result < 0 ? 0 : result; // If no cuts are possible, return 0
    }
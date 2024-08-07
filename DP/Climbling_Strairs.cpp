#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int climbStairsHelper(int i, int n, vector<int> &dp)
    {
        if(dp[i] != -1) return dp[i];
        if(i == n) return dp[i] = 1;
        if(i > n) return dp[i] = 0;
        int ans = climbStairsHelper(i+1, n, dp) + climbStairsHelper(i+2, n, dp);
        return dp[i] = ans;
    }
    int climbStairs(int n) {
        // vector<int> dp(n+2, -1);
        // dp[n + 1] = 0;
        // dp[n] = 1;
        // int last =
        int last = 0;
        int secLast = 1; 
        int ans = 0;
        for(int i=n-1; i>=0; i--)
        {
            ans = last + secLast;
            last = secLast;
            secLast = ans;
        } 
        return ans;
    }
};
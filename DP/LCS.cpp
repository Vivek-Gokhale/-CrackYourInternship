#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    // int dp[1000][1000];
    // int Helper(int i, string &text1, int j, string &text2)
    // {
    //     if(i < 0 || j < 0)return 0;
    //     if(dp[i][j] != -1)return dp[i][j];
    //     if(text1[i] == text2[j])
    //     {
    //         return 1+Helper(i-1, text1, j-1, text2);
    //     }
    //     return dp[i][j] = max(Helper(i-1,text1, j, text2),Helper(i,text1, j-1, text2));
    // }


    int dp[1001][1001];
    int Helper(int i, string &text1, int j, string &text2)
    {
        if(i == 0 || j == 0)return 0;
        if(dp[i][j] != -1)return dp[i][j];
        if(text1[i-1] == text2[j-1])
        {
            return 1+Helper(i-1, text1, j-1, text2);
        }
        return dp[i][j] = max(Helper(i-1,text1, j, text2),Helper(i,text1, j-1, text2));
    }


    int longestCommonSubsequence(string text1, string text2) {
        // int n = text1.size();
        // int m = text2.size();
        // memset(dp, -1, sizeof(dp));
        // return Helper(n-1, text1, m-1, text2);

        int n = text1.size();
        int m = text2.size();
        // memset(dp, -1, sizeof(dp));
        // vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        // for(int i=0; i<=n; i++)
        // dp[i][0] = 0;
        // for(int j=0; j<=m; j++)
        // dp[0][j] = 0;
        // for(int i=1; i<=n; i++){
        //     for(int j=1; j<=m; j++){
        //         if(text1[i-1] == text2[j-1])
        //         {
        //             dp[i][j] =  1+dp[i-1][j-1];
        //         }
        //         else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        //     }
        // }
        //         // return Helper(n, text1, m, text2);
        //         return dp[n][m];
        vector<int> prev(m+1, 0);
        
        for(int j=0; j<=m; j++)
        prev[j] = 0;
        for(int i=1; i<=n; i++){
            vector<int> curr(m+1, 0);
            
            for(int j=1; j<=m; j++){
                if(text1[i-1] == text2[j-1])
                {
                    curr[j] =  1+prev[j-1];
                }
                else curr[j] = max(prev[j],curr[j-1]);
            }
            prev = curr;
        }
                // return Helper(n, text1, m, text2);
                return prev[m];
    }
};
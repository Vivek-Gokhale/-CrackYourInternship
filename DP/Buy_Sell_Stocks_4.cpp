#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    // int dp[100001][2][3];
    // int Helper(int idx, int canBuy, int k, vector<int>& prices)
    // {


    //     if(idx == prices.size() || k == 0)return 0;
    //     if(dp[idx][canBuy][k] != -1)return dp[idx][canBuy][k];
    //     int profit = 0;
    //     if(canBuy)
    //     {
    //         profit = max(-prices[idx] + Helper(idx+1, 0, k, prices), Helper(idx+1, 1, k, prices));
    //     }
    //     else
    //     {
    //         profit = max(prices[idx] + Helper(idx+1, 1, k-1, prices), Helper(idx+1, 0, k, prices));
    //     }
    //     return dp[idx][canBuy][k] = profit;
    // }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        // memset(dp, -1, sizeof(dp));
        // return Helper(0, 1, 2, prices);
        
        //  vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(3, 0)));

        // // Base cases: already set to 0 by the initialization

        // // Fill the dp array from the bottom-up
        // for (int i = n-1; i >= 0; i--) {
        //     for (int j = 0; j <= 1; j++) {  // j represents whether we can buy (1) or not (0)
        //         for (int k = 1; k <= 2; k++) {  // k represents the number of transactions left
        //             if (j) {
        //                 // If we can buy, we have two choices: buy or not buy
        //                 dp[i][j][k] = max(-prices[i] + dp[i+1][0][k], dp[i+1][1][k]);
        //             } else {
        //                 // If we can't buy, we have two choices: sell or not sell
        //                 dp[i][j][k] = max(prices[i] + dp[i+1][1][k-1], dp[i+1][0][k]);
        //             }
        //         }
        //     }
        // }        return dp[0][1][2];


        // vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(3, 0)));
        vector<vector<int>> front(2, vector<int>(3, 0));
        // Base cases: already set to 0 by the initialization

        // Fill the dp array from the bottom-up
        for (int i = n-1; i >= 0; i--) {
            vector<vector<int>> curr(2, vector<int>(3, 0));
            for (int j = 0; j <= 1; j++) {  // j represents whether we can buy (1) or not (0)
                for (int k = 1; k <= 2; k++) {  // k represents the number of transactions left
                    if (j) {
                        // If we can buy, we have two choices: buy or not buy
                        curr[j][k] = max(-prices[i] + front[0][k], front[1][k]);
                    } else {
                        // If we can't buy, we have two choices: sell or not sell
                        curr[j][k] = max(prices[i] + front[1][k-1], front[0][k]);
                    }
                }
            }
            front = curr;
        }        return front[1][2];


    }
};
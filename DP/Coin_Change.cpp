#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
   /* int Helper(vector<int>& coins, int amount, int idx, vector<vector<int>> &dp) {
        
        if(dp[idx][amount] != -1)return dp[idx][amount];
        if(idx == 0){
            if(amount % coins[0] == 0)
            return dp[idx][amount] = amount / coins[0];
            else 
            return dp[idx][amount] = 1e9;
        }
        int not_take = 0 + Helper(coins, amount, idx-1, dp);
        int take = 1e9;
        if(coins[idx] <= amount)
        {
            take = 1 + Helper(coins, amount- coins[idx], idx, dp);
        }
        return dp[idx][amount] = min(take, not_take);
    }
    */
    
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        // vector<vector<int>> dp(n, vector<int>(amount+1, 0));
        vector<int> prev(amount+1, 0);
        vector<int> curr(amount+1, 0);
        // int ans =  Helper(coins, amount, n-1, dp);
        for(int i=0; i<=amount; i++)
        {
            if(i % coins[0] == 0)
            prev[i] = i / coins[0];
            else 
            prev[i] = 1e9;
        }
        for(int i=1; i<n; i++){
            for(int j=0; j<=amount; j++){
                 int not_take = 0 + prev[j];
                 int take = 1e9;
                 if(coins[i] <= j)
                 {
                    take = 1 + curr[j-coins[i]];
                 }
                    curr[j] = min(take, not_take);
            }
            prev = curr;
        }
        int ans = prev[amount];
        if(ans >= 1e9)return -1;
        return ans;
    }
};
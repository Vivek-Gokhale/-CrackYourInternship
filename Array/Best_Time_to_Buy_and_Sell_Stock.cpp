// 121. Best_Time_to_Buy_and_Sell_Stock

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();
        // vector<int> dp(n,-1);
        // dp[n-1] = prices[n-1];
        // for(int i=n-2; i>=0; i--)
        // {
        //     dp[i] = max(dp[i+1], prices[i]);
        // } 
        // int maxProfit = 0;
        // for(int i=0; i<n; i++)
        // {
        //     maxProfit = max(maxProfit, dp[i] - prices[i]);
        // }
        // return maxProfit;
        int minPrice = INT_MAX;
        int maxProfit = 0;
        for(int i=0; i<n; i++)
        {
            minPrice = min(minPrice, prices[i]);
            maxProfit = max(maxProfit, prices[i] - minPrice);
        }
        return maxProfit;
    }
};
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    // int dp[301][301];
    // int Helper(int i, int j, vector<int> &nums)
    // {
    //     if(i > j)return 0;
    //     if(dp[i][j] != -1)return dp[i][j];
    //     int maxi = -1e9;
    //     for(int k=i; k<=j; k++)
    //     {
    //         int coins = nums[i-1] * nums[k] *nums[j+1] + Helper(i, k-1, nums) + Helper(k+1, j, nums);
    //         maxi = max(maxi, coins);
    //     }
    //     return dp[i][j] = maxi;
    // }

    int maxCoins(vector<int>& nums) {
        // memset(dp, -1, sizeof(dp));
        int n = nums.size();
        nums.push_back(1);
        nums.insert(nums.begin(), 1);
        vector<vector<int>> dp(n+2, vector<int>(n+2, 0));
        for(int i=n; i>=1; i--)
        {
            for(int j=1; j<=n; j++)
            {
                 if (i > j) continue;
                int maxi = -1e9;
                for(int k=i; k<=j; k++)
                {
                    int coins = nums[i-1] * nums[k] *nums[j+1] + dp[i][k-1] + dp[k+1][j];
                    maxi = max(maxi, coins);
                }
                dp[i][j] = maxi;
            }
        }
        // return Helper(1, n, nums);    
        return dp[1][n];
    }
};
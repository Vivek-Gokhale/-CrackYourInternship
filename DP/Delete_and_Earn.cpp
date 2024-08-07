#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int Helper(int idx, vector<int> &vec, vector<int> &dp) {
        if (idx < 0) return 0;
        if (dp[idx] != -1) return dp[idx];
        
        int take = vec[idx] + Helper(idx - 2, vec, dp);
        int non_take = Helper(idx - 1, vec, dp);
        
        dp[idx] = max(take, non_take);
        return dp[idx];
    }

    int deleteAndEarn(vector<int>& nums) {
        vector<int> vec(10001, 0);
        for (auto it : nums)
            vec[it] += it;

        vector<int> dp(10001, -1);
        return Helper(10000, vec, dp);
    }
};

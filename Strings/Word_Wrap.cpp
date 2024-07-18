// 121. Word Wrap

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int Helper(vector<int> &nums, int i, int k, vector<int> &dp) {
        int n = nums.size();
        if (i == n) return 0;
        if (dp[i] != -1) return dp[i];

        int sum = 0;
        int ans = INT_MAX;
        for (int j = i; j < n; j++) {
            sum += nums[j];
            if (sum > k) break;
            int cost;
            if (j == n - 1) {
                cost = Helper(nums, j + 1, k, dp); // No extra space cost for the last line
            } else {
                cost = (k - sum) * (k - sum) + Helper(nums, j + 1, k, dp);
            }
            ans = min(ans, cost);
            sum++; // Adding space between words
        }
        return dp[i] = ans;
    }

    int solveWordWrap(vector<int> nums, int k) {
        int n = nums.size();
        vector<int> dp(n + 1, -1);
        return Helper(nums, 0, k, dp);
    }
};
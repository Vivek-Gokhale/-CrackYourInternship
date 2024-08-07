#include <bits/stdc++.h>
using namespace std;
class Solution {
public:

    int Helper(int idx, int k, vector<int> &arr, vector<vector<int>> &dp) {
        if (k == 0) return 1; // If k is 0, we can achieve the sum with an empty subset
        if (idx == 0) return arr[0] == k ? 1 : 0; // If only one element is there, check if it equals k

        if (dp[idx][k] != -1) return dp[idx][k]; // Return already computed result

        int not_take = Helper(idx - 1, k, arr, dp); // Do not include the current element
        int take = 0;
        if (arr[idx] <= k) {
            take = Helper(idx - 1, k - arr[idx], arr, dp); // Include the current element if it is less than or equal to k
        }

        return dp[idx][k] = (not_take || take);
    }

    bool canPartition(vector<int>& nums) {
        int totalSum = 0;
        int n = nums.size();
        for (int it : nums)
            totalSum += it;

        // If the total sum is odd, we cannot partition it into two equal subsets
        if (totalSum % 2 != 0) return false;

        int target = totalSum / 2;
        // vector<vector<int>> dp(n, vector<int>(target + 1, 0));
        vector<int> prev(target+1, 0);
        
        prev[0] = 1;

        if (nums[0] <= target)
        prev[nums[0]] = 1;


        for(int i=1; i<n; i++){
            vector<int> curr(target+1, 0);
            curr[0] = 1;
            for(int k=1; k<=target; k++){
                int not_take = prev[k];
                int take = 0;
                if(nums[i] <= k)
                {
                    take = prev[k-nums[i]];
                }
                curr[k] = (not_take || take);
            }
            prev = curr;

        }
        return prev[target];
        // return Helper(n - 1, target, nums, dp) == 1;
    }
};
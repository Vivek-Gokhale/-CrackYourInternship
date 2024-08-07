#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool Helper(int idx, vector<int>& stones, int k, unordered_map<int, int> &umap,  vector<vector<int>> &dp) {
        if (idx == stones.size() - 1) return true;
        if(dp[idx][k] != -1)return dp[idx][k];
        for (int step = k - 1; step <= k + 1; ++step) {
            if (step > 0 && umap.find(stones[idx] + step) != umap.end()) {
                if (Helper(umap[stones[idx] + step], stones, step, umap, dp)) {
                    return dp[idx][k] = true;
                }
            }
        }

        return dp[idx][k]   = false;
    }

    bool canCross(vector<int>& stones) {
        if (stones[1] != 1) return false; // The first jump must be 1 unit.
        int n = stones.size();
        unordered_map<int, int> umap;
        for (int i = 0; i < stones.size(); ++i) {
            umap[stones[i]] = i;
        }
        vector<vector<int>> dp(n, vector<int>(n,-1));
        return Helper(1, stones, 1, umap, dp);
        //  if (stones[1] != 1) return false; // The first jump must be 1 unit.
        
        // int n = stones.size();
        // unordered_map<int, int> umap;
        // for (int i = 0; i < n; ++i) {
        //     umap[stones[i]] = i;
        // }
        
        // vector<vector<bool>> dp(n, vector<bool>(n, false)); // dp[i][j] indicates if it's possible to reach stone i with jump j
        
        // dp[0][0] = true; // Base case: it's possible to reach the first stone (stone 0) with 0 jump
        
        // // Iterate through stones and jumps to fill the DP table
        // for (int i = 0; i < n; ++i) {
        //     for (int j = 0; j <= i; ++j) {
        //         if (dp[i][j]) {
        //             for (int k = j - 1; k <= j + 1; ++k) {
        //                 if (k > 0 && umap.find(stones[i] + k) != umap.end()) {
        //                     int nextStoneIdx = umap[stones[i] + k];
        //                     dp[nextStoneIdx][k] = true;
        //                 }
        //             }
        //         }
        //     }
        // }
        
        // // Check if it's possible to reach the last stone with any valid jump
        // for (int j = 0; j < n; ++j) {
        //     if (dp[n - 1][j]) return true;
        // }
        
        // return false;
    }
};
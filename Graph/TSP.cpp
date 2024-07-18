// 11. TSP


#include <bits/stdc++.h>
using namespace std;
int tsp(vector<vector<int>> &cost, int mask, int city, int visited_all, int n, vector<vector<int>> &dp) {
    if (mask == visited_all) {
        return cost[city][0];
    }
    if (dp[mask][city] != -1) {
        return dp[mask][city];
    }
    int ans = INT_MAX;
    for (int c = 0; c < n; c++) {
        if (!((1 << c) & mask)) {
            ans = min(ans, cost[city][c] + tsp(cost, mask | (1 << c), c, visited_all, n, dp));
        }
    }
    return dp[mask][city] = ans;
}

int total_cost(vector<vector<int>> cost) {
    int n = cost.size();
    int visited_all = (1 << n) - 1;
    vector<vector<int>> dp(visited_all + 1, vector<int>(n, -1));
    return tsp(cost, 1, 0, visited_all, n, dp);
}
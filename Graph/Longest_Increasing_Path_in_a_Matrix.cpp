// . Longest Increasing Path in a Matrix
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int rows[4] = {-1, 0, 1, 0};
    int cols[4] = {0, 1, 0, -1};

    bool isSafe(int i, int j, int m, int n) {
        return i >= 0 && j >= 0 && i < m && j < n;
    }

    int dfs(vector<vector<int>>& matrix, vector<vector<int>>& memo, int i, int j, int m, int n) {
        if (memo[i][j] != -1) return memo[i][j];
        int maxPath = 1;

        for (int k = 0; k < 4; k++) {
            int newRow = i + rows[k];
            int newCol = j + cols[k];
            if (isSafe(newRow, newCol, m, n) && matrix[newRow][newCol] > matrix[i][j]) {
                maxPath = max(maxPath, 1 + dfs(matrix, memo, newRow, newCol, m, n));
            }
        }
        memo[i][j] = maxPath;
        return maxPath;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;

        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> memo(m, vector<int>(n, -1));

        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                ans = max(ans, dfs(matrix, memo, i, j, m, n));
            }
        }

        return ans;
    }
};

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int rows[4] = {-1, 0, 1, 0};
        int cols[4] = {0, 1, 0, -1};
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        int n = grid.size();
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        vector<vector<int>> dist(n, vector<int>(n, 1e9));
        pq.push({grid[0][0], {0, 0}});
        dist[0][0] = grid[0][0];
        while (!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            int depth = it.first;
            int r = it.second.first;
            int c = it.second.second;
            visited[r][c] = true;
            if (r == n - 1 && c == n - 1) return depth;
            for (int i = 0; i < 4; i++) {
                int newRow = r + rows[i];
                int newCol = c + cols[i];
                if (newRow >= 0 && newCol >= 0 && newRow < n && newCol < n && !visited[newRow][newCol]) {
                    int newDepth = max(depth, grid[newRow][newCol]);
                    if (newDepth < dist[newRow][newCol]) {
                        dist[newRow][newCol] = newDepth;
                        pq.push({dist[newRow][newCol], {newRow, newCol}});
                    }
                }
            }
        }
        return dist[n - 1][n - 1];
    }
};

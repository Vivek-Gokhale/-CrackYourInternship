// 121. As Far from land as possible

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        queue<vector<int>> q;
        int rows[4] = {-1, 0, 1, 0};
        int cols[4] = {0, 1, 0, -1};
        int maxi = 0;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(grid[i][j] == 1)
                {
                    q.push({i, j, 0});
                }
            }
        }
        while(!q.empty())
        {
            auto it = q.front();
            int x = it[0];
            int y = it[1];
            int cnt = it[2];
            q.pop();
            maxi = max(maxi, cnt);
            for(int i=0; i<4; i++)
            {
                int newRow = x + rows[i];
                int newCol = y + cols[i];
                if(newRow < 0 || newCol < 0 || newRow >= n || newCol >= n || grid[newRow][newCol] == 1)
                continue;
                q.push({newRow, newCol, cnt+1});
                grid[newRow][newCol] = 1; 
            }
        }
        return maxi == 0 ? -1 : maxi;
    }
};
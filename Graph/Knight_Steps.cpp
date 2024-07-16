// 11. Knight_Steps


#include <bits/stdc++.h>
using namespace std;
int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
	{
	    // Code here
	     if (KnightPos[0] == TargetPos[0] && KnightPos[1] == TargetPos[1]) {
        return 0; // No moves needed if starting and target positions are the same
    }

    int minMoves = INT_MAX;
    queue<pair<int, int>> q;
    int rows[] = {-1, -1, 1, 1, -2, -2, 2 , 2};
    int cols[] = {-2, 2, -2, 2, -1, 1, -1, 1};
    int level = 0;

    vector<vector<bool>> visited(N + 1, vector<bool>(N + 1, false)); // To track visited positions
    q.push({KnightPos[0], KnightPos[1]});
    visited[KnightPos[0]][KnightPos[1]] = true;

    while (!q.empty()) {
        int siz = q.size();
        while (siz--) {
            auto it = q.front();
            q.pop();
            int x = it.first;
            int y = it.second;

            if (x == TargetPos[0] && y == TargetPos[1]) {
                minMoves = min(minMoves, level);
                return minMoves; // Return as soon as the target is reached
            }

            for (int i = 0; i < 8; i++) { // There are exactly 8 possible moves for a knight
                int newRow = x + rows[i];
                int newCol = y + cols[i];

                if (newRow < 1 || newCol < 1 || newRow > N || newCol > N || visited[newRow][newCol])
                    continue;

                visited[newRow][newCol] = true;
                q.push({newRow, newCol});
            }
        }
        level++;
    }
    
    return -1; // Return -1 if target position is unreachable
	    
	}


#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	int orangesRotting(vector<vector<int>>& grid) {
		// Your code goes here
		queue<pair<pair<int, int>, int>> q;
		int m = grid.size();
		int n = grid[0].size();
		int visisted[m][n];
		for(int i=0; i<m; i++)
		{
			for(int j=0; j<n; j++)
			{
				if(grid[i][j] == 2)
				{
					q.push({{i,j},0});
					visisted[i][j] = 2;
				}
				else
				{
					visisted[i][j] = 0;
				}
			}
		}
		int delRow[] = {-1, 0, +1, 0};
			int delCol[] = {0, +1, 0, -1};
			int tm= 0;
		while(!q.empty())
		{
			int row = q.front().first.first;
			int col = q.front().first.second;
			int time = q.front().second;
			
			tm = max(tm, time);
			q.pop();
			for(int i=0; i<4; i++)
			{
				int mrow = row+delRow[i];
				int mcol = col+delCol[i];
				if(mrow >= 0 && mrow < m && mcol >= 0 && mcol < n && visisted[mrow][mcol] != 2 && grid[mrow][mcol] == 1)
				{
					q.push({{mrow, mcol},time + 1});
					visisted[mrow][mcol] = 2;
				}
			}
			
			
		}
		for(int i=0; i<m; i++)
			{
				for(int j=0;j<n; j++)
				{
					if(visisted[i][j] != 2 && grid[i][j] == 1 )
					return -1;
				}

			}
		return tm;
	}
};
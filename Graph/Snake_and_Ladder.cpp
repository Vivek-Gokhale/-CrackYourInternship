// 11. Snake and Bridge


#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	pair<int, int> getCoordinate(int num, int n)
	{
		int RT = (num-1) / n;
		int RB = (n-1) - RT;
		int col = (num-1) % n;
		if((RB % 2 == 0 && n % 2 == 0)|| (RB % 2 == 1 && n % 2 == 1))
		{
			col = (n-1) - col;
		}
		return make_pair(RB, col);
	}
	int snakesAndLadders(vector<vector<int>>& board) {
		// Your code goes here
		int n = board.size();
		vector<int> dist(n * n + 1, -1);
		
		queue<int> que;
		dist[1] = 0;
		que.push(1);
		while(!que.empty())
		{
			int curr = que.front();
			que.pop();
			for(int next = curr+1; next<=min(curr + 6, n * n); next++)
			{
				pair<int, int> coordinates = getCoordinate(next, n);
				int row = coordinates.first;
				int col = coordinates.second;
				int destination = board[row][col] != -1 ? board[row][col] : next;
				if(dist[destination] == -1)
				{
					dist[destination] = dist[curr] +1;
					que.push(destination);
				}
			}
		}
			
		return dist[n * n];
	}
};
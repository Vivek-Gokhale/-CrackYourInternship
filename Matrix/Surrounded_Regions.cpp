// 121. Surrounded Regions

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int rows[4] = {-1, 0, 1, 0};
    int cols[4] = {0, 1, 0, -1};
    void dfs(vector<vector<char>>& board, vector<vector<int>> &visited, int i, int j)
    {
        visited[i][j] = 1;
        int m = board.size();
        int n = board[0].size();
        for(int k=0; k<4; k++)
        {
            int newRow = i + rows[k];
            int newCol = j + cols[k];
            if(newRow >=0 && newCol >=0 && newRow < m && newCol < n && !visited[newRow][newCol] && board[newRow][newCol] == 'O')
            {
                dfs(board, visited, newRow, newCol);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>> visited(m, vector<int>(n, 0));
        for(int j=0; j<n; j++)
        {
            if(!visited[0][j] && board[0][j] == 'O')
            {
                dfs(board, visited, 0, j);
            }
            if(!visited[m-1][j] && board[m-1][j] == 'O')
            {
                dfs(board, visited, m-1, j);
            }
        }
        for(int i=0; i<m; i++)
        {
            if(!visited[i][0] && board[i][0] == 'O')
            {
                dfs(board, visited, i, 0);
            }
            if(!visited[i][n-1] && board[i][n-1] == 'O')
            {
                dfs(board, visited, i, n-1);
            }
        }
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(board[i][j] == 'O' && !visited[i][j])
                board[i][j] = 'X';
            }
        }
        return;
    }
};
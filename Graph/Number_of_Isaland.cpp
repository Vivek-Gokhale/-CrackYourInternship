// 11. Number_of_Isaland


#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    
    void exploreHelper(int i, int j, vector<vector<char>>& grid, int n, int m)
    {
        if(i < 0 || i >= n || j < 0 || j >= m || grid[i][j] != '1' || grid[i][j] == '2')return;
        grid[i][j] = '2';
        exploreHelper(i-1, j, grid, n, m);
        exploreHelper(i, j+1, grid, n, m);
        exploreHelper(i+1, j, grid, n, m);
        exploreHelper(i, j-1, grid, n, m);
    }
    int numIslands(vector<vector<char>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    int ans = 0;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(grid[i][j] == '1')
            {
                exploreHelper(i, j, grid, n, m);
                ans++;
            }
        }
    }   
    return ans; 
    }
};
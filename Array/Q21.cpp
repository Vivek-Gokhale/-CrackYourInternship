// 11. Game of Life

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
     vector<int> getCells(int i, int j, int m, int n, vector<vector<int>>& board) {
        int live = 0;
        int dead = 0;
        for (int i1 = i - 1; i1 <= i + 1; i1++) {
            for (int j1 = j - 1; j1 <= j + 1; j1++) {
                if (i1 == i && j1 == j) continue; // Skip the cell itself
                if (i1 < 0 || i1 >= m || j1 < 0 || j1 >= n) continue; // Skip out of bounds cells
                if (board[i1][j1] == 1)
                    live++;
                else
                    dead++;
            }
        }
        return {live, dead};
    }

    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();

        vector<vector<int>> temp(m, vector<int>(n));
        for (int i = 0; i < m; i++) { // Correct loop bounds
            for (int j = 0; j < n; j++) { // Correct loop bounds
                vector<int> cells = getCells(i, j, m, n, board);
                int liveC = cells[0];
                int deadC = cells[1];
                if (board[i][j] == 1) {
                    if (liveC < 2)
                        temp[i][j] = 0;
                    else if (liveC == 2 || liveC == 3)
                        temp[i][j] = 1;
                    else if (liveC > 3)
                        temp[i][j] = 0;
                } else {
                    if (liveC == 3)
                        temp[i][j] = 1;
                }
            }
        }
        board = temp; // Update the original board
    }
};
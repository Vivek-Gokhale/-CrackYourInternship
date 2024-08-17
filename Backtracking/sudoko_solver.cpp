#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isPossible(vector<vector<char>>& board, char ch, int row, int col) {
        for (int i = 0; i < 9; i++) {
            // Check if the character exists in the current row, column, or 3x3 subgrid.
            if (board[i][col] == ch) return false;
            if (board[row][i] == ch) return false;
            if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == ch) return false;
        }
        return true;
    }
    
    bool Helper(vector<vector<char>>& board) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == '.') {
                    for (char ch = '1'; ch <= '9'; ch++) {
                        if (isPossible(board, ch, i, j)) {
                            board[i][j] = ch;  // Place the character.
                            if (Helper(board)) return true;  // Recursively try solving the rest.
                            board[i][j] = '.';  // Backtrack if the solution was not correct.
                        }
                    }
                    return false;  // No valid number found, backtrack.
                }
            }
        }
        return true;  // If the entire board is filled.
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        Helper(board);  // Start the backtracking process.
    }
};

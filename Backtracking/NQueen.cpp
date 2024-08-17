#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<string>> ans;
    bool isSafePosition(int i, int j, vector<string> &chessBoard, int n)
    {
        int x = i;
        int y = j;
        while(x >= 0)
        {
            if(chessBoard[x][y] == 'Q') return false;
            x--;
        }
        x = i;
        y = j;
        while(x >= 0 && y >= 0)
        {
            if(chessBoard[x][y] == 'Q') return false;
            x--;
            y--;
        }
        x = i;
        y = j;
        while(x >= 0 && y < n)
        {
            if(chessBoard[x][y] == 'Q') return false;
            x--;
            y++;
        }
        return true;
    }
    void solveHelper(int i, int n, vector<string> &chessBoard)
    {
        if(i == n)
        {
            ans.push_back(chessBoard);
            return;
        }
        for(int j = 0; j < n; j++)
        {
            if(isSafePosition(i, j, chessBoard, n))
            {
                chessBoard[i][j] = 'Q';
                solveHelper(i+1, n, chessBoard);
                chessBoard[i][j] = '.';
            }
        }
        return;
    }
    vector<vector<string>> solveNQueens(int n) {
        string row(n,'.');
        vector<string> chessBoard(n, row);  
        solveHelper(0, n, chessBoard);
        return ans;  
    }
};
// Word Search

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:

    bool findWord(int i, int j, int idx, int n, int m, vector<vector<char>>& board, string &word)
    {
        if(idx >= word.size())return true;
        if(i < 0 || i >= n || j < 0 || j >= m)return false;
        if(board[i][j] != word[idx])return false;
        char temp = board[i][j];
        board[i][j] = '#';
        bool flag = findWord(i-1, j, idx+1, n, m, board, word) || findWord(i, j+1, idx+1, n, m, board, word) || findWord(i+1, j, idx+1, n, m, board, word) || findWord(i, j-1, idx+1, n, m, board, word);
        board[i][j] = temp;
        return flag;
    }
    bool exist(vector<vector<char>>& board, string word) {
    int n = board.size();
    int m = board[0].size();
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(board[i][j] == word[0] && findWord(i, j, 0, n, m, board, word))
            return true;
        }
    }    
    return false;
    }
};
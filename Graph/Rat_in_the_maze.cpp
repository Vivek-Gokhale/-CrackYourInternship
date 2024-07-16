 // 11. Rat_in_the_maze


#include <bits/stdc++.h>
using namespace std;
 vector<string> ans;
    bool Helper(int i, int j, vector<vector<int>> &m, int n, string &path)
    {
        if (i < 0 || j < 0 || i >= n || j >= n) return false;
        if (m[i][j] != 1) return false;
        if (i == n-1 && j == n-1)
        {
            ans.push_back(path);
            return true;
        }
        
        m[i][j] = 2; // mark the cell as visited
        
        // Try moving Down
        if (i + 1 < n && m[i+1][j] == 1) {
            path.push_back('D');
            Helper(i+1, j, m, n, path);
            path.pop_back();
        }
        
        // Try moving Left
        if (j - 1 >= 0 && m[i][j-1] == 1) {
            path.push_back('L');
            Helper(i, j-1, m, n, path);
            path.pop_back();
        }
        
        // Try moving Right
        if (j + 1 < n && m[i][j+1] == 1) {
            path.push_back('R');
            Helper(i, j+1, m, n, path);
            path.pop_back();
        }
        
        // Try moving Up
        if (i - 1 >= 0 && m[i-1][j] == 1) {
            path.push_back('U');
            Helper(i-1, j, m, n, path);
            path.pop_back();
        }
        
        m[i][j] = 1; // unmark the cell as visited
        
        return false;
    }

    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        string path = "";
        if (m[0][0] == 1) {
            Helper(0, 0, m, n, path);
        }
        return ans;
    }
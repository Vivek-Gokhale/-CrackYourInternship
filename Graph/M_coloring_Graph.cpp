// 11.  M_coloring_Graph


#include <bits/stdc++.h>
using namespace std;
bool isSafe(int node, vector<int> &colors, bool graph[101][101], int col, int n)
    {
        for(int k=0; k<n; k++)
        {
            if(k != node && graph[k][node] == 1 && colors[k] == col)
            return false;
        }
        return true;
    }
    bool solve(int node, vector<int> &colors, bool graph[101][101], int m, int n)
    {
        if(node == n)
        {
            return true;
        }
        for(int i=1; i<=m; i++)
        {
            if(isSafe(node, colors, graph, i, n))
            {
                colors[node] = i;
                if(solve(node+1, colors, graph, m, n))
                {
                    return true;
                    
                }
                colors[node] = 0;
            }
        }
        return false;
    }
    
    bool graphColoring(bool graph[101][101], int m, int n) {
        // your code here
        vector<int> colors(n, 0);
        if(solve(0, colors, graph, m, n))
        return true;
        return false;
    }
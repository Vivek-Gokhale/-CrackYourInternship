#include <bits/stdc++.h>
using namespace std;
class Solution{
public:
    // Function to determine if graph can be coloured with at most M colours such
    // that no two adjacent vertices of graph are coloured with same colour.
 bool isPossible(int node, bool graph[101][101], vector<int> &colors, int col, int n)
    {
        for (int i = 0; i < n; i++)
        {
            if (i != node && graph[node][i] == 1 && colors[i] == col)
                return false;
        }
        return true;
    }

    // Recursive function to solve the M-coloring problem
    bool Helper(int node, vector<int> &colors, bool graph[101][101], int m, int n)
    {
        if (node == n) return true;
        
        for (int col = 1; col <= m; col++)
        {
            if (isPossible(node, graph, colors, col, n))
            {
                colors[node] = col;
                
                if (Helper(node + 1, colors, graph, m, n))
                    return true;
                
                // Backtrack
                colors[node] = 0;
            }
        }
        return false;
    }

    // Main function to determine if the graph can be colored with at most M colors
    bool graphColoring(bool graph[101][101], int m, int n) {
        vector<int> colors(n, 0); // Size of the colors vector should be n
        return Helper(0, colors, graph, m, n);
    }
};

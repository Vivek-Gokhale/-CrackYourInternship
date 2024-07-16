// 11.  Is_Graph_Bipartite


#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool dfs(vector<vector<int>>& graph, vector<int> &visited, vector<int> &color, int node, int wanted_color)
    {
        if(visited[node] == 1)
        {
            if(wanted_color != color[node])
            return false;
            return true;
        }
        visited[node]  = 1;
        color[node] = wanted_color;
        for(auto it : graph[node])
        {
            if(dfs(graph, visited, color, it, 1-wanted_color) == false)
            return false;
        }
        return true;

    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> visited(n, 0);
        vector<int> color(n);
        for(int i=0; i<n; i++)
        {
            if(visited[i] == 0)
            {
                if(dfs(graph, visited, color, i, 0) == false)
                return false;
            }
        }
        return true;
    }
};
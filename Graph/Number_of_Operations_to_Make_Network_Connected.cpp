// 11.  Number_of_Operations_to_Make_Network_Connected


#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void dfs(vector<int> adj[], vector<int> &visited, int node)
    {
        if(visited[node])return;
        visited[node]  = true;
        for(auto it : adj[node])
        {
            if(!visited[it])
            dfs(adj, visited, it);
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size() < n-1)return -1;
        vector<int> adj[n];
        for(auto it : connections)
        {
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> visited(n, false);
        int ans = 0;
        for(int i=0; i<n; i++)
        {
            if(!visited[i])
            {
                dfs(adj, visited, i);
                ans++;
            }
        }
        return ans-1;

    }
};
 // 11. Critical Connections


#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int timer = 1;
    void dfs(int node, int parent, vector<int> adj[], int tin[], int low[], vector<int> &visited, vector<vector<int>> &ans)
    {
        visited[node] = 1;
        tin[node] = low[node] = timer++;
        
        for(auto it : adj[node])
        {
            if(it == parent) continue;
            
            if(!visited[it])
            {
                dfs(it, node, adj, tin, low, visited, ans);
                
                low[node] = min(low[node], low[it]);
                
                if(low[it] > tin[node])
                {
                    ans.push_back({node, it});
                }
            }
            else
            {
                low[node] = min(low[node], tin[it]);
            }
        }
    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int> adj[n];
        vector<vector<int>> ans;
        int tin[n];
        int low[n];
        vector<int> visited(n, 0);
        
       
        for(auto &it : connections)
        {
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
      
                dfs(0, -1, adj, tin, low, visited, ans);
     
        
        return ans;
    }
};

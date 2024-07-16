// 11. BSF


#include <bits/stdc++.h>
using namespace std;
vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
       vector<int> ans;
    vector<bool> visited(V, false);
    queue<int> q;
    
    // Assuming BFS starts from node 0
    q.push(0);
    visited[0] = true;

    while(!q.empty()) {
        int node = q.front();
        q.pop();
        ans.push_back(node);

        // Traverse all adjacent vertices
        for(auto it : adj[node]) {
            if(!visited[it]) {
                q.push(it);
                visited[it] = true;
            }
        }
    }
    
    return ans;
    }
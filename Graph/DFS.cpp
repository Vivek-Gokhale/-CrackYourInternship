// 11. DFS


#include <bits/stdc++.h>
using namespace std;
void Helper(vector<int> adj[], vector<int> &visited, vector<int> &ans, int node) {
    if(visited[node]) return;
    visited[node] = true;
    ans.push_back(node);
    for(auto it : adj[node]) {
        if(!visited[it]) {
            Helper(adj, visited, ans, it);
        }
    }
}

vector<int> dfsOfGraph(int V, vector<int> adj[]) {
    vector<int> visited(V, false);
    vector<int> ans;
    Helper(adj, visited, ans, 0);
    return ans;
}
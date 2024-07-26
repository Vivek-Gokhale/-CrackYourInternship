#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> root_result;
    vector<int> count;
    int N;
    
    int dfsCounter(vector<vector<int>>& adj, int curr_node, int prev_node, int curr_depth) {
        int total_count = 1;
        root_result[0] += curr_depth;
        for (auto child : adj[curr_node]) {
            if (child == prev_node) continue;
            total_count += dfsCounter(adj, child, curr_node, curr_depth + 1);
        }
        count[curr_node] = total_count;
        return total_count;
    }
    
    void dfsFiller(vector<vector<int>>& adj, int parent_node, int prev_node, vector<int>& result) {
        for (auto child : adj[parent_node]) {
            if (child == prev_node) continue;
            result[child] = result[parent_node] - count[child] + (N - count[child]);
            dfsFiller(adj, child, parent_node, result);
        }
    }
    
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        N = n;
        vector<vector<int>> adj(n);
        for (auto& e : edges) {
            int u = e[0];
            int v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        root_result.assign(n, 0);
        count.assign(n, 0);
        
        dfsCounter(adj, 0, -1, 0);
        
        vector<int> result(n, 0);
        result[0] = root_result[0];
        
        dfsFiller(adj, 0, -1, result);
        
        return result;
    }
};
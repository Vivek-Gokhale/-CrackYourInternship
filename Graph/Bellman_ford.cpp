// 11. Bellman Ford algo


#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    /*  Function to implement Bellman Ford
    *   edges: vector of vectors which represents the graph
    *   S: source vertex to start traversing graph with
    *   V: number of vertices
    */
   vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
    // Initialize distances from source to all vertices as infinite
    vector<int> dist(V, 1e8);
    dist[S] = 0;

    // Relax all edges |V|-1 times
    for (int i = 0; i < V - 1; i++) {
        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            if (dist[u] != 1e8 && dist[u] + wt < dist[v]) {
                dist[v] = dist[u] + wt;
            }
        }
    }

    // Check for negative-weight cycles
    for (auto& edge : edges) {
        int u = edge[0];
        int v = edge[1];
        int wt = edge[2];
        if (dist[u] != 1e8 && dist[u] + wt < dist[v]) {
            return {-1};  // Negative cycle detected
        }
    }

    return dist;
}
};
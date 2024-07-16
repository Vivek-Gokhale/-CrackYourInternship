 // 11. Cycle_in_Undirected_graph


#include <bits/stdc++.h>
using namespace std;
bool Helper(vector<int> adj[], vector<bool> &visited, int node, int parent)
    {
        visited[node] = true;
        for (auto it : adj[node])
        {
            if (!visited[it])
            {
                if (Helper(adj, visited, it, node))
                    return true;
            }
            else if (it != parent) // If an adjacent vertex is visited and it's not the parent, there is a cycle
            {
                return true;
            }
        }
        return false;
    }
    
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        vector<bool> visited(V, false); // Keep track of visited nodes
        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                if (Helper(adj, visited, i, -1)) // Start DFS from each unvisited node
                    return true;
            }
        }
        return false;
    }
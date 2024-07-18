// 11. Minimum Spanning Tree


#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    // Comparator for sorting edges by weight
    static bool cmp(const vector<int>& a, const vector<int>& b) {
        return a[0] < b[0];
    }

    // Union-Find data structure with path compression and union by rank
    class UnionFind {
    public:
        UnionFind(int n) : parent(n), rank(n, 0) {
            for (int i = 0; i < n; ++i) {
                parent[i] = i;
            }
        }

        int find(int u) {
            if (u != parent[u]) {
                parent[u] = find(parent[u]);
            }
            return parent[u];
        }

        bool unionSets(int u, int v) {
            int pu = find(u);
            int pv = find(v);
            if (pu == pv) return false;

            if (rank[pu] < rank[pv]) {
                parent[pu] = pv;
            } else if (rank[pu] > rank[pv]) {
                parent[pv] = pu;
            } else {
                parent[pv] = pu;
                ++rank[pu];
            }
            return true;
        }

    private:
        vector<int> parent;
        vector<int> rank;
    };

    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[]) {
        vector<vector<int>> edges;

        // Collect all edges with their weights
        for (int i = 0; i < V; ++i) {
            for (auto it : adj[i]) {
                if (i < it[0]) { // Ensure each edge is added only once
                    edges.push_back({it[1], i, it[0]});
                }
            }
        }

        // Sort the edges based on their weights
        sort(edges.begin(), edges.end(), cmp);

        UnionFind uf(V);
        int mstWeight = 0;

        // Kruskal's algorithm
        for (const auto& edge : edges) {
            int weight = edge[0];
            int u = edge[1];
            int v = edge[2];

            if (uf.unionSets(u, v)) {
                mstWeight += weight;
            }
        }

        return mstWeight;
    }
};

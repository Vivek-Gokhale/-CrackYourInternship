// 11. Making Larger Island


#include <bits/stdc++.h>
using namespace std;
class DisjointSet {
public:
    vector<int> parent, size;

    DisjointSet(int n) {
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findParent(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findParent(parent[node]);
    }

    void unionize(int u, int v) {
        int upu = findParent(u);
        int upv = findParent(v);
        if (upu != upv) {
            if (size[upu] < size[upv]) {
                parent[upu] = upv;
                size[upv] += size[upu];
            } else {
                parent[upv] = upu;
                size[upu] += size[upv];
            }
        }
    }
};

class Solution {
public:
    bool isSafe(int i, int j, int n) {
        return i >= 0 && j >= 0 && i < n && j < n;
    }

    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DisjointSet ds(n * n);
        int ans = 0;

        // Connect all components
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    int rows[4] = {-1, 0, 1, 0};
                    int cols[4] = {0, 1, 0, -1};
                    for (int k = 0; k < 4; k++) {
                        int newRow = i + rows[k];
                        int newCol = j + cols[k];
                        if (isSafe(newRow, newCol, n) && grid[newRow][newCol] == 1) {
                            ds.unionize(i * n + j, newRow * n + newCol);
                        }
                    }
                }
            }
        }

        // Try flipping each 0 and calculate the largest possible island
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    int rows[4] = {-1, 0, 1, 0};
                    int cols[4] = {0, 1, 0, -1};
                    unordered_set<int> components;
                    for (int k = 0; k < 4; k++) {
                        int newRow = i + rows[k];
                        int newCol = j + cols[k];
                        if (isSafe(newRow, newCol, n) && grid[newRow][newCol] == 1) {
                            components.insert(ds.findParent(newRow * n + newCol));
                        }
                    }
                    int size = 1; // Counting the flipped cell itself
                    for (auto it : components) {
                        size += ds.size[it];
                    }
                    ans = max(ans, size);
                }
            }
        }

        // Check the largest component without flipping any 0
        for (int i = 0; i < n * n; i++) {
            ans = max(ans, ds.size[ds.findParent(i)]);
        }

        return ans;
    }
};

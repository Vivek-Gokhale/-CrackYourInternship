// 11. Redundant Connections


#include <bits/stdc++.h>
using namespace std;
class DisjointSet 
{
	public: 
	vector<int> parent, size;
	DisjointSet(int n)
	{
		parent.resize(n+1);
		size.resize(n+1);
		for(int i=1; i<=n; i++)
		{
			parent[i] = i;
			size[i] = 1;
		}
	}
	int findParent(int node)
	{
		if(node == parent[node])
		return node;
		return parent[node] = findParent(parent[node]);
        
	}

	void unionize(int u, int v)
	{
		int upu = findParent(u);
		int upv = findParent(v);
		if(size[upu] < size[upv])
		{
			parent[upu] = upv;
			size[upv] += size[upu];
		}
		else
		{
			
			parent[upv] = upu;
			size[upu] += size[upv];
		}
	}
};
class Solution {
public:
	vector<int> findRedundantConnection(vector<vector<int>>& edges) {
		// Your code goes here
		int n = edges.size();
		DisjointSet ds(n);
		for(auto e : edges)
		{
			if(ds.findParent(e[0]) == ds.findParent(e[1]))
			return e;
			else
			ds.unionize(e[0], e[1]);
		}
		return {};

	}
};
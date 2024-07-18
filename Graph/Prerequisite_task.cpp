
// 11.  Prerequisite Tasks


#include <bits/stdc++.h>
using namespace std;
bool isPossible(int N,int P, vector<pair<int, int> >& prerequisites) {
	    // Code here
	    vector<int> adj[N];
	    int cnt = 0;
	    vector<int> indegree(N, 0);
	    queue<int> q;
	    for(auto & it : prerequisites)
	    {
	        int u = it.first;
	        int v = it.second;
	        adj[v].push_back(u);
	    }
	    for(int i=0; i<N; i++)
	    {
	        for(auto it : adj[i])
	        {
	            indegree[it]++;
	        }
	    }
	    for(int i=0; i<N; i++)
	    {
	        if(indegree[i] == 0)
	        q.push(i);
	    }
	    while(!q.empty())
	    {
	        int node = q.front();
	        q.pop();
	        cnt++;
	        for(auto it : adj[node])
	        {
	            indegree[it]--;
	            if(indegree[it] == 0)
	            {
	                q.push(it);
	            }
	        }
	    }
	    return cnt == N ? true : false;
	    
	}
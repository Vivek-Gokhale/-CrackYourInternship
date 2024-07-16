 // 11. Cycle_in_directed_graph


#include <bits/stdc++.h>
using namespace std;
bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<int> indegree(V, 0);
        int ans = 0;
        queue<int> q;
        for(int i=0; i<V; i++)
        {
            for(auto &it : adj[i])
            {
                indegree[it]++;
            }
        }
        for(int i=0; i<V; i++)
        {
            if(indegree[i] == 0)
            {
                q.push(i);
            }
        }
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            ans++;
            for(auto &it : adj[node])
            {
                indegree[it]--;
                if(indegree[it] == 0)
                q.push(it);
            }
        }
        if(ans == V)return false;
        return true;
    }
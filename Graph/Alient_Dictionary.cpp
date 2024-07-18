// 121. Alien Dictioanry

#include <bits/stdc++.h>
using namespace std;
class Solution{
    public:
    vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    vector<int> indegree(V, 0);
	    vector<int> ans;
	    queue<int> q;
	    int cnt = 0;
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
	        ans.push_back(node);
	        for(auto it : adj[node])
	        {
	            indegree[it]--;
	            if(indegree[it] == 0)
	            {
	                q.push(it);
	            }
	        }
	        
	    }
	    return ans;
	    
	    
	}
    string findOrder(string dict[], int N, int K) {
        //code here
        vector<int> adj[K];
        for(int i=0; i<N-1; i++)
        {
            string s1 = dict[i];
            string s2 = dict[i+1];
            int len = min(s1.size(), s2.size());
            for(int i=0; i<len; i++)
            {
                if(s1[i] != s2[i])
                {
                    adj[s1[i]-'a'].push_back(s2[i]-'a');
                    break;
                }
            }
        }
        vector<int> topo = topoSort(K, adj);
        string ans = "";
        for(auto it : topo)
        {
            ans += char(it+'a');
        }
        return ans;
    }
};
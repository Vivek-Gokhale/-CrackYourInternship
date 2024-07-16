//Kosarajus_Algorithm
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void dfs(vector<vector<int>>& adj, vector<int>& visited, stack<int>& st, int node)
{
    if (visited[node]) return;
    visited[node] = true;
    for (auto it : adj[node])
    {
        if (!visited[it])
        {
            dfs(adj, visited, st, it);
        }
    }
    st.push(node);
}

void dfsT(vector<vector<int>>& adjList, vector<int>& visited, int node)
{
    if (visited[node]) return;
    visited[node] = true;
    for (auto it : adjList[node])
    {
        if (!visited[it])
        {
            dfsT(adjList, visited, it);
        }
    }
}

int kosaraju(int V, vector<vector<int>>& adj)
{
    vector<int> visited(V, false);
    stack<int> st;

    // Step 1: Order vertices by finishing time
    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
            dfs(adj, visited, st, i);
    }

    // Step 2: Transpose the graph
    vector<vector<int>> adjList(V);
    for (int i = 0; i < V; i++)
    {
        for (auto it : adj[i])
        {
            adjList[it].push_back(i);
        }
    }

    // Step 3: Process all vertices in order defined by Stack
    fill(visited.begin(), visited.end(), false);
    int scc = 0;
    while (!st.empty())
    {
        int node = st.top();
        st.pop();
        if (!visited[node])
        {
            scc++;
            dfsT(adjList, visited, node);
        }
    }
    return scc;
}

// Example usage
int main()
{
    int V = 5;
    vector<vector<int>> adj(V);
    adj[0].push_back(2);
    adj[2].push_back(1);
    adj[1].push_back(0);
    adj[0].push_back(3);
    adj[3].push_back(4);

    cout << "Number of Strongly Connected Components: " << kosaraju(V, adj) << endl;

    return 0;
}

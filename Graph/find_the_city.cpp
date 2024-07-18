// 11. Find the City With the Smallest Number of Neighbors at a Threshold Distance


#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> adjMat(n, vector<int>(n, 1e9));
        for(int i=0; i<n; i++)
        {
            adjMat[i][i] = 0;
        }
        for(auto it : edges)
        {
            int u = it[0];
            int v = it[1];
            int dist = it[2];
            adjMat[u][v] = min(adjMat[u][v], dist);
            adjMat[v][u] = min(adjMat[v][u], dist);
        }
        for(int k=0; k<n; k++)
        {
            for(int i=0; i<n; i++)
            {
                for(int j=0; j<n; j++)
                {
                    adjMat[i][j] = min(adjMat[i][j], adjMat[i][k]+adjMat[k][j]);
                }
            }
        }
        int reachable = INT_MAX;
        int city = -1;
        int count = 0;  
        for(int i=0; i<n; i++)
        {
            count = 0;
            for(int j=0; j<n; j++)
            {
                if(adjMat[i][j] > 0 && adjMat[i][j] != 1e9 && adjMat[i][j] <= distanceThreshold)
                {
                    count++;
                }
                
            }
            cout << count << endl;
            if(count < reachable)
            {
                reachable = count;
                city = i;
            }
            if(count == reachable)
            {
                city = max(city, i);
                reachable = count;
            }
        }
        return city;
    }
};
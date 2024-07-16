// 11.  Time_Needed_to_inform_All_employees


#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<int> adj[n];
        queue<pair<int, int>> q; // To store {employee, accumulated time}
        int maxTime = 0;

        for(int i = 0; i < n; i++) {
            if(manager[i] != -1) {
                adj[manager[i]].push_back(i);
            }
        }

        // Start BFS from the headID
        q.push({headID, 0});

        while(!q.empty()) {
            int emp = q.front().first;
            int currTime = q.front().second;
            q.pop();

            // Update the maximum time
            maxTime = max(maxTime, currTime);

            for(auto it : adj[emp]) {
                q.push({it, currTime + informTime[emp]});
            }
        }

        return maxTime;
    }
};

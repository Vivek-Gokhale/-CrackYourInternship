#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
   
      priority_queue<int> maxHeap;
        int currentFuel = startFuel;
        int refuels = 0;
        int i = 0;
        
        while (currentFuel < target) {
            // Push all reachable stations' fuel to the max-heap
            while (i < stations.size() && stations[i][0] <= currentFuel) {
                maxHeap.push(stations[i][1]);
                i++;
            }
            
            // If we cannot reach any further and maxHeap is empty, return -1
            if (maxHeap.empty()) {
                return -1;
            }
            
            // Refuel with the largest available fuel from past stations
            currentFuel += maxHeap.top();
            maxHeap.pop();
            refuels++;
        }
        
        return refuels;

    }
};
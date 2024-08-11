// C++ program to acquire all n coins  
#include<bits/stdc++.h> 
using namespace std; 
class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int totalCost = 0;
        int maxTime = neededTime[0];  // Max time in the current group of the same color
        int groupCost = 0;            // Total cost of the current group

        for (int i = 1; i < colors.size(); ++i) {
            if (colors[i] == colors[i-1]) {
                groupCost += neededTime[i-1];
                maxTime = max(maxTime, neededTime[i-1]);
            } else {
                if (groupCost > 0) {
                    groupCost += neededTime[i-1];
                    maxTime = max(maxTime, neededTime[i-1]);
                    totalCost += (groupCost - maxTime);
                }
                // Reset for the next group
                groupCost = 0;
                maxTime = neededTime[i];
            }
        }

        // Handle the last group
        if (groupCost > 0) {
            groupCost += neededTime.back();
            maxTime = max(maxTime, neededTime.back());
            totalCost += (groupCost - maxTime);
        }

        return totalCost;
    }
};

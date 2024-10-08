#include<bits/stdc++.h> 
using namespace std; 
class Solution {
public:
    static bool cmp(vector<int> &a, vector<int> &b) {
        if (a[0] == b[0])
            return a[1] < b[1];
        return a[0] < b[0];
    }

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.empty()) return 0;
        
        sort(intervals.begin(), intervals.end(), cmp);
        
        int cnt = 0;
        int b = intervals[0][1];
        
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] < b) {
                cnt++;
                b = min(b, intervals[i][1]); // Choose the interval with the smallest end to minimize future overlaps
            } else {
                b = intervals[i][1];
            }
        }
        
        return cnt;
    }
};

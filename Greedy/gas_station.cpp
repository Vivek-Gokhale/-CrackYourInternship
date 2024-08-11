
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int l = 0, r = 0;
        int n = gas.size(), remainGas = 0;;

        // since the answer guarantees to be unique, 
        //       it returns -1 if remainGas is still less than 0 after
        //       going through all the stations
        while(l < n) {
            remainGas += (gas[r%n] - cost[r%n]);
            if(r-l+1 == n && remainGas >= 0) {
                return l;  
            }

            r++;
            // move the left pointer and reset the remainGas
            if(remainGas < 0) {
                l = r, remainGas = 0;
            }
        }
        return -1;
    }
};
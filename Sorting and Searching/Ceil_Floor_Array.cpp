// Ceil The Floor

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> getFloorAndCeil(int x, vector<int> arr) {
        // code here
        int ceilVal = -1;
        int floorVal = -1;
        for(int i=0; i<arr.size(); i++)
        {
            if(arr[i] >= x)
            {
                if(ceilVal == -1)
                {
                    ceilVal = arr[i];
                }
                else
                {
                    ceilVal = min(ceilVal , arr[i]);
                }
            }
            if(arr[i] <= x)
            {
                if(floorVal == -1)
                {
                    floorVal = arr[i];
                }
                else
                {
                    floorVal = max(floorVal , arr[i]);
                }
            }
        }
        return {floorVal, ceilVal};
    }
};
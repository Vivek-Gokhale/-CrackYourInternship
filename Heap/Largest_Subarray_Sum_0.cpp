#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int maxLen(vector<int>& arr, int n) {
        // Your code here
        unordered_map<int, int> mp;
        mp[0] = -1;
        int currSum = 0;
        int ans = 0;
        for(int i=0; i<n; i++)
        {
            currSum += arr[i];
            if(mp.find(currSum) != mp.end())
            {
                ans = max(ans, i-mp[currSum]);
            }
            else
            {
                mp[currSum] = i;
            }
        }
        return ans;
        
        
    }
};
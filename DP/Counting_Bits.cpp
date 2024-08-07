#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int getBits(int x)
    {
        int setBitsCnt = 0;
        for(int i=0; i<32; i++)
        {
            if(x & (1 << i))setBitsCnt++;
        }
        return setBitsCnt;
    }
    vector<int> countBits(int n) {
    vector<int> ans(n+1, 0);
    for(int i=0; i<=n; i++)
    {
        ans[i] = getBits(i);
    }   
    return ans; 
    }
};
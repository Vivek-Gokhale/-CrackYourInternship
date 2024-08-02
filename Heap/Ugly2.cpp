#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> dp(n+1);
        dp[1] = 1;
        int i1 = 1;
        int i2 = 1;
        int i3 = 1;

        for(int i=2; i<=n; i++)
        {
            int n1 = dp[i1] * 2;
            int n2 = dp[i2] * 3;
            int n3 = dp[i3] * 5;
            int minUgly = min(n1, min(n2, n3));
            dp[i] = minUgly;
            if(minUgly == n1)
            i1++;
            if(minUgly == n2)
            i2++;
            if(minUgly == n3)
            i3++;
            

        }
        return dp[n];
    }
};
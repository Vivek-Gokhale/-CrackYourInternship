// Chocolate Distribution Problem

#include <bits/stdc++.h>
using namespace std;
long long findMinDiff(vector<long long> a, long long n, long long m){
    //code
    long long minDiff = INT_MAX;
    sort(a.begin(), a.end());
   for (int i = 0; i <= n - m; i++) {
        minDiff = std::min(a[i + m - 1] - a[i], minDiff);
    }
    return minDiff;
    
    }   
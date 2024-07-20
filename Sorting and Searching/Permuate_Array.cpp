// 121. Permuate Array 

#include <bits/stdc++.h>
using namespace std;

    static bool cmp(long long a, long long b)
    {
        return a > b;
    }
    bool isPossible(long long a[], long long b[], int n, long long k) {
        // Your code goes here
        sort(a, a+n);
        sort(b, b+n, cmp);
        for(int i=0; i<n; i++)
        {
            if(a[i] + b[i] < k)return false;
        }
        return true;
        
    }
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void Helper(vector<int> &vec, int &ans, int n, int curr)
    {
        if(curr >= n+1)
        {
            ans++;
            return;
        }
        for(int i=1; i<=n; i++)
        {
            if(vec[i] == 0 && (curr%i == 0 || i % curr == 0))
            {
                vec[i] = curr;
                Helper(vec, ans, n, curr+1);
                vec[i] = 0;
            }
        }
    }
    int countArrangement(int n) {
        vector<int> vec(n+1, 0);
        int ans = 0;
        Helper(vec, ans, n, 1);
        return ans;
    }
};
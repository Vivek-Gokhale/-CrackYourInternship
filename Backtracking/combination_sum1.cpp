#include <bits/stdc++.h>
using namespace std;
class Solution {
public:

    void Helper(int currVal,int n, int k, vector<vector<int>> &ans,vector<int> &temp)
    {
        if(k == 0)
        {
            ans.push_back(temp);
            return;
        }
        for(int i=currVal; i<=n; i++)
        {
            temp.push_back(i);
            Helper(i+1, n, k-1, ans, temp);
            temp.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
    if(n == 1)return {{1}};
    vector<int> temp;
    vector<vector<int>> ans;
    Helper(1,n, k, ans, temp);  
    return ans;  
    }
};
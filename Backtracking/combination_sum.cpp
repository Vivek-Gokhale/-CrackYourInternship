
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:

    void Helper(int idx,vector<vector<int>> &ans, vector<int>& candidates, vector<int> &temp, int target)
    {
       
        
            if(target == 0)
            {
                ans.push_back(temp);
                return;
            }
            if(target < 0)return;
           
        
        for(int i=idx; i<candidates.size(); i++)
        {
            if(i > idx && candidates[i] == candidates[i-1])
            continue;
            if(target >= candidates[i])
            {
                temp.push_back(candidates[i]);
                Helper(i+1, ans, candidates, temp, target-candidates[i]);
                temp.pop_back();
            }
            
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    sort(candidates.begin(), candidates.end());
    vector<vector<int>> ans;
    vector<int> temp; 
    Helper(0, ans, candidates, temp, target);  
    return ans; 
    }
};
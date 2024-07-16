// remove_all_duplicated
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
    vector<int> ans;
    int idx = 0;
    ans.push_back(nums[0]);
    int n = nums.size();
    for(int i=1; i<n; i++)
    {
        if(nums[i] != ans[idx])
        {
            ans.push_back(nums[i]);
            idx++;
        }
        
    }
    int k = ans.size();
    for(int i=0; i<k; i++)
    {
        nums[i] = ans[i];
    }
    return k;     
    }
};



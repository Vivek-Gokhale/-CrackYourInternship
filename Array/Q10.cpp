// FInd all duplicates in array
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
    // unordered_map<int, int> umap;
    // for(auto it : nums)
    // {
    //     umap[it]++;
    // }    
    // vector<int> ans;

    // for(auto it : umap)
    // {
    //     if(it.second == 2)ans.push_back(it.first);
    // }
    
    // return ans;
    vector<int> ans;
    int n = nums.size();
    for(int i=0; i<n; i++)
    {
        int num = abs(nums[i]);
        int idx = num - 1;
        if(nums[idx] < 0)
        ans.push_back(abs(nums[i]));
        else 
        nums[idx] = -1 * nums[idx]; 

    }
    return ans;
    }
};
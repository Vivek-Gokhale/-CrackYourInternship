#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void Helper(int idx, vector<int>& nums, vector<int> &temp, vector<vector<int>> &ans)
    {
        int n = nums.size();
        ans.push_back(temp);
        for(int i=idx; i<n; i++)
        {
            if(i != idx && nums[i] == nums[i-1])
            continue;
            temp.push_back(nums[i]);
            Helper(i+1, nums, temp, ans);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> temp;
        vector<vector<int>> ans;
        Helper(0, nums, temp, ans);
        return ans;
    }
};
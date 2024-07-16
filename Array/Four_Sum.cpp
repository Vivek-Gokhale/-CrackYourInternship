// 11. Four_Sum

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> ans;
    void twoSumSolver(vector<int>& nums,long long target, int i, int j, int a, int b)
    {
        while(i < j)
        {
            long long twoSum = nums[i] + nums[j];
            if(twoSum > target)
            j--;
            else if(twoSum < target)
            i++;
            else 
            {
                while(i < j && nums[i] == nums[i+1])i++;
                while(i < j && nums[j] == nums[j-1])j--;
                ans.push_back({a, b, nums[i], nums[j]});
                i++;
                j--;
            }
        }
    }
    void threeSumSolver(vector<int>& nums,long long target, int i, int n, int a)
    {
        int k = i;
        for(i; i<n; i++)
        {
            if(i > k && nums[i] == nums[i-1])continue;
            twoSumSolver(nums, target-nums[i], i+1, n, a, nums[i]);
        }
    }
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    for(int i=0; i<n; i++)
    {
        if(i > 0 && nums[i] == nums[i-1])continue;
        threeSumSolver(nums, target-nums[i], i+1, n-1, nums[i]);
    }    
    return ans;
    }
};
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:

    //take or not take approaches
    void Helper(int idx, vector<vector<int>> &ans, vector<int> &nums, vector<int> &temp)
    {
        if(idx >= nums.size())
        {
            ans.push_back(temp);
            return;
        }
        temp.push_back(nums[idx]);
        Helper(idx+1, ans, nums, temp);
        temp.pop_back();  
        Helper(idx+1, ans, nums, temp);
    } 
    vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> ans;
    vector<int> temp;
    Helper(0, ans, nums, temp);
    return ans;
    }
};
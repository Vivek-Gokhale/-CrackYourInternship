#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void Helper(int firstIdx, vector<int> &nums, set<vector<int>> &set) {
        if (firstIdx == nums.size()) {
            set.insert(nums);
            return;
        }
        for (int i = firstIdx; i < nums.size(); i++) {
            swap(nums[i], nums[firstIdx]);
            Helper(firstIdx + 1, nums, set);
            swap(nums[i], nums[firstIdx]);
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>> set;
        vector<vector<int>> ans;
        Helper(0, nums, set);
        for (auto it : set) {
            ans.push_back(it);
        }
        return ans;
    }
};
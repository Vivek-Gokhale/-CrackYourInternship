#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        vector<int> ans;
        int rem = nums.size() - k;
        for(auto it : nums)
        {
            while(ans.size() && rem && it < ans.back())
            {
                ans.pop_back();
                rem--;
            }
            ans.push_back(it);
        }
        while(rem--)
        ans.pop_back();
        return ans;
    }
};
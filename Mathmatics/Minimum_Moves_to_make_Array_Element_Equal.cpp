// 121. Minimum Moves to make array element equal

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int median = nums.size() / 2;
        int ans =0;
        for(int i=0; i<nums.size(); i++)
        {
            ans += abs(nums[median] - nums[i]);
        }
        return ans;

    }
};
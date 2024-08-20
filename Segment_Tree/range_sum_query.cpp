#include <bits/stdc++.h>
using namespace std;
class NumArray {
public:
    vector<int> vec;
    
    NumArray(vector<int>& nums) {
        int n = nums.size();
        vec.resize(n, 0);
        vec[0] = nums[0];
        for(int i = 1; i < n; i++) {
            vec[i] = vec[i-1] + nums[i];
        }
    }
    
    int sumRange(int left, int right) {
        if (left == 0) {
            return vec[right];
        } else {
            return vec[right] - vec[left-1];
        }
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */

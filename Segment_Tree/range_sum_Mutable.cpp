#include <bits/stdc++.h>
using namespace std;
class NumArray {
public:
    vector<int> tree;
    int n;
    
    void buildTree(int i, int l, int r, vector<int>& nums) {
        if (l == r) {
            tree[i] = nums[l];
            return;
        }
        int mid = l + (r - l) / 2;
        buildTree(2 * i + 1, l, mid, nums);
        buildTree(2 * i + 2, mid + 1, r, nums);
        tree[i] = tree[2 * i + 1] + tree[2 * i + 2];
    }
    
    void updateHelper(int i, int l, int r, int index, int val) {
        if (l == r) {
            tree[i] = val;
            return;
        }
        int mid = l + (r - l) / 2;
        if (index <= mid) {
            updateHelper(2 * i + 1, l, mid, index, val);
        } else {
            updateHelper(2 * i + 2, mid + 1, r, index, val);
        }
        tree[i] = tree[2 * i + 1] + tree[2 * i + 2];
    }
    
    int sumHelper(int i, int l, int r, int start, int end) {
        if (l > end || r < start) return 0;
        if (l >= start && r <= end) return tree[i];
        int mid = l + (r - l) / 2;
        return sumHelper(2 * i + 1, l, mid, start, end) + sumHelper(2 * i + 2, mid + 1, r, start, end);
    }
    
    NumArray(vector<int>& nums) {
        n = nums.size();
        tree.resize(4 * n);  
        buildTree(0, 0, n - 1, nums);
    }
    
    void update(int index, int val) {
        updateHelper(0, 0, n - 1, index, val);
    }
    
    int sumRange(int left, int right) {
        return sumHelper(0, 0, n - 1, left, right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */

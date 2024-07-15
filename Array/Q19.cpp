// Reverse pairs

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int cnt;

    void merge(vector<int>& nums, int s , int e, int mid) {
        int n = mid - s + 1; 
        int m = e - mid;
        vector<int> temp(n + m);
        int k = 0;
        int i = s;
        int j = mid + 1; 
        
        // Count reverse pairs
        for (int i = s; i <= mid; i++) {
            while (j <= e && nums[i] > 2LL * nums[j]) {
                j++;
            }
            cnt += (j - (mid + 1));
        }
        
        // Reset j for merging
        j = mid + 1;
        
        // Merge the two halves
        while (i <= mid && j <= e) {
            if (nums[i] <= nums[j]) {
                temp[k++] = nums[i++];
            } else {
                temp[k++] = nums[j++];
            }
        } 
        while (i <= mid) {
            temp[k++] = nums[i++];
        }
        while (j <= e) {
            temp[k++] = nums[j++];
        }
        
        k = 0;
        for (int i = s; i <= e; i++) {
            nums[i] = temp[k++];
        }
    }

    void Helper(vector<int>& nums, int l, int r) {
        if (l >= r) return;
        int mid = l + (r - l) / 2;
        Helper(nums, l, mid);
        Helper(nums, mid + 1, r);
        merge(nums, l, r, mid);
    }

    int reversePairs(vector<int>& nums) {
        cnt = 0;
        int n = nums.size();
        if (n == 0) return 0;
        Helper(nums, 0, n - 1);
        return cnt;
    }
};

// 11. Unique_permutation

#include <bits/stdc++.h>
using namespace std;

  void Helper(int firstIdx, std::vector<int> &nums, std::set<std::vector<int>> &st) {
        if (firstIdx == nums.size()) {
            st.insert(nums);
            return;
        }
        for (int i = firstIdx; i < nums.size(); i++) {
            std::swap(nums[i], nums[firstIdx]);
            Helper(firstIdx + 1, nums, st);
            std::swap(nums[i], nums[firstIdx]);
        }
    }

    std::vector<std::vector<int>> uniquePerms(std::vector<int> &arr, int n) {
        std::sort(arr.begin(), arr.end());
        std::set<std::vector<int>> st;
        Helper(0, arr, st);
        std::vector<std::vector<int>> ans(st.begin(), st.end());
        return ans;
    }
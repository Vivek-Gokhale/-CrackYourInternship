// Subarray_Sums_Divisible_by_K

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
    

        int cnt = 0;
        int sum = 0;
        unordered_map<int, int> umap;
        umap[0] = 1;
        for(auto it : nums)
        {
            sum += it;
            int rem = sum % k;
            if (rem < 0) {
                rem += k;
            }
            if(umap.find(rem) != umap.end())
            {
                cnt += umap[rem];
                umap[rem] += 1;
            }
            else
            {
                umap[rem] = 1;
            }
        }
        return cnt;
    }
};
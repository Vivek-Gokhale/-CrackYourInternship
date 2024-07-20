// 121. Array element product except itself

#include <bits/stdc++.h>
using namespace std;
class Solution{
  public:
    // nums: given vector
    // return the Product vector P that holds product except self at each index
    vector<long long int> productExceptSelf(vector<long long int>& nums, int n) {
        vector<long long int> prefix(n, 1);
        vector<long long int> suffix(n, 1);
        vector<long long int> ans(n);

        // Compute prefix products
        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] * nums[i - 1];
        }

        // Compute suffix products
        for (int i = n - 2; i >= 0; i--) {
            suffix[i] = suffix[i + 1] * nums[i + 1];
        }

        // Compute the result by multiplying prefix and suffix products
        for (int i = 0; i < n; i++) {
            ans[i] = prefix[i] * suffix[i];
        }

        return ans;
    }
};

//  Split Array Largest Sum

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int getSplitCnt(vector<int>& nums, int maxSum)
    {
        int splitCnt = 1;
        int currSum  = 0;
        for(int i=0; i<nums.size(); i++)
        {
            if(currSum + nums[i] <= maxSum)
            {
                currSum += nums[i];
            }
            else
            {
                splitCnt++;
                currSum = nums[i];
            }
        }
        return splitCnt;
    }
    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);
        int ans = 0;
        while(low <= high)
        {
            int mid = low + (high-low) / 2;
            int splitCnt = getSplitCnt(nums, mid);
            if(splitCnt <= k)
            {
                ans = mid;
                high = mid - 1;
            }
            else
            {
                low = mid+1;
            }

        }
        return ans;
    }
};
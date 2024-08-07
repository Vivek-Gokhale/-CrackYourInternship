#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
   /* int Helper(int idx, int prev, vector<int>& nums, vector<vector<int>> &dp)
    {
        if(idx == nums.size())return 0;
        if(dp[idx][prev+1] != -1)return dp[idx][prev+1];
        int len = 0;
        len = Helper(idx+1, prev, nums, dp);
        if(prev == -1 || nums[idx] > nums[prev])
        {
            len = max(len, 1+Helper(idx+1, idx, nums, dp));
        }
        return dp[idx][prev+1] = len;
    } 
    */

    int lengthOfLIS(vector<int>& nums) {
     /*	int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        // return Helper(0, -1, nums, dp);
        for (int i = n-1; i >= 0; i--)
        {
            for (int j = i-1; j >= -1; j--)
            {
                int len = dp[i+1][j+1]; // Note that j+1 is used for the correct index
                if (j == -1 || nums[i] > nums[j])
                {
                    len = max(len, 1 + dp[i+1][i+1]);
                }
                dp[i][j+1] = len; // Correctly assign the computed value to dp[i][j+1]
            }
        }
        return dp[0][-1+1]; */

   /*     int n = nums.size();
        vector<int> front(n+1, 0);
        // return Helper(0, -1, nums, dp);
        for (int i = n-1; i >= 0; i--)
        {
            vector<int> curr(n+1, 0);
            for (int j = i-1; j >= -1; j--)
            {
                int len = front[j+1]; // Note that j+1 is used for the correct index
                if (j == -1 || nums[i] > nums[j])
                {
                    len = max(len, 1 + front[i+1]);
                }
                curr[j+1] = len; // Correctly assign the computed value to dp[i][j+1]
            }
            front = curr;
        }
        return front[-1+1]; */
      /*  int n = nums.size();
		vector<int> dp(n,1);
        vector<int> hash(n);
        for(int i=0; i<n; i++)
        hash[i] = i;

		int lisLength = 1;
		for(int i=0; i<n; i++)
		{
			for(int j=i-1; j>=0; j--)
			{
				if(nums[i] > nums[j] && 1+dp[j] > dp[i])
				dp[i] = dp[j] + 1;
                hash[i] = j;
			}
			lisLength = max(lisLength, dp[i]);
		}
        int ans = -1;
        int lastIndex =-1;
        
        for(int i=0; i<=n-1; i++){
            if(dp[i]> ans){
                ans = dp[i];
                lastIndex = i;
            }
        }
        vector<int> temp;
        temp.push_back(nums[lastIndex]);
        while(hash[lastIndex] != lastIndex)
        {
            lastIndex = hash[lastIndex];
            temp.push_back(nums[lastIndex]);
        }
        reverse(temp.begin(), temp.end());
		return lisLength;
        */
        vector<int> dp;
        dp.push_back(nums[0]);
        int len = 1;
        for(int i=1; i<nums.size(); i++)
        {
            if(dp.back() < nums[i])
            {
                dp.push_back(nums[i]);
                len++;
            }
            else 
            {
                int pos = lower_bound(dp.begin(), dp.end(), nums[i])-dp.begin();
                dp[pos] = nums[i];
            }
        }
        
        return len;
    }
};
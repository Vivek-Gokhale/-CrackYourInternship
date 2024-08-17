#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    
    unordered_map<int,int> dp;  
    bool dfs(vector<int> &nums,int &tot,int k,int ind,int mask,int sum)
    {
        if(k==1)  //rest of all nums sum equal to target
            return true;
        if(sum==0) //if current subset sum equal 0 then move to next subset
            return dp[mask] = dfs(nums,tot,k-1,0,mask,tot);
        if(dp.find(mask)!=dp.end())
            return dp[mask];
        if(ind==nums.size())
            return false;
        bool pick=false,npick=false;
        int prev=mask;
        if(!(mask&(1<<ind)))
        {
            mask|=(1<<ind);
            if((sum-nums[ind])>=0)
                pick=dfs(nums,tot,k,ind+1,mask,sum-nums[ind]);
            if(pick) //we can stop here it will reduce height of decission tree | to avoid TLE
                return dp[mask] = true;
            mask=prev;
        }
        npick=dfs(nums,tot,k,ind+1,mask,sum);
        return dp[mask] = npick;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) 
    {
        int n=nums.size(),tot=0;
        for(int &i:nums)
            tot+=i;
        if(tot%k)
            return false;
        tot/=k;
        return dfs(nums,tot,k,0,0,tot);
    }
};
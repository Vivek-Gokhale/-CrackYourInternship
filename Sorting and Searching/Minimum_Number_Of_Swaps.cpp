// 121. Minimum number of swap to sort array

#include <bits/stdc++.h>
using namespace std;
class Solution 
{
    public:
    //Function to find the minimum number of swaps required to sort the array. 
	int minSwaps(vector<int>&nums)
	{
	    // Code here
	    int n = nums.size();
	    vector<int> temp(nums.begin(), nums.end());
        sort(temp.begin(), temp.end());
        unordered_map<int, int> mp;
        for(int i=0; i<n; i++)
        mp[temp[i]] = i;
        int cnt = 0;
        for(int i=0; i<n; i++)
        {
            while(nums[i] != mp[nums[i]])
            {
                cnt++;
                swap(nums[i], nums[mp[nums[i]]]);
            }
        }
        return cnt;
	}
};
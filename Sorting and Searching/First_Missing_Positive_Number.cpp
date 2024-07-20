// 121. First Missing Positive number

/*
    approach 1;hashmap 
    approach 2
    1.range of number from [1,n]should be in ideal case
    2.use array element as index
*/

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
    // unordered_map<int, int> umap;
    // int upperBound = INT_MIN;
    // for(auto it : nums)
    // {
    //     umap[it] = 1;
    //     upperBound = max(upperBound, it);
    // } 
    // if(upperBound < 0)return 1;
    // for(int i=1; i<=upperBound; i++)
    // {
    //     if(umap.find(i) == umap.end())
    //     return i;
    // }
    // return upperBound+1;
    // int n = nums.size();
    // sort(nums.begin(), nums.end());
    // int cnt = 1;
    // int i=0;
    // while(i < n)
    // {
    //     while(i < n-1 && nums[i] == nums[i+1])
    //     i++;
    //     if(nums[i] <= 0){i++; continue;}
    //     if(nums[i] == cnt)
    //     cnt++;
    //     else return cnt;
    //     i++;
    // }
    // if(nums[n-1] < 0)return 1;
    // return nums[n-1]+1;

    int n = nums.size();
    bool containsOne = false;
    for(int i=0; i<n; i++)
    {
        if(nums[i] == 1){
            containsOne = true;
            break;
        }
    }
    if(!containsOne)
    return 1;

    for(int i=0; i<n; i++)
    {
        if(nums[i] <= 0 || nums[i] > n)nums[i] = 1;
    }

    for(int i=0; i<n; i++)
    {
        int num = abs(nums[i]);
        int idx = num - 1;
        if(nums[idx] < 0)continue;
        nums[idx] = -1 * nums[idx];
    }

    for(int i=0; i<n; i++)
    {
        if(nums[i] > 0)
        return i+1;
    }
    return n+1;


    }
};
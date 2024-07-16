// 287. Find_the_Duplicate_Number
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    // int smallerThanMid(int mid, vector<int>&nums)
    // {
    //     int count = 0;
    //     for(auto it : nums)
    //     {
    //         if(it <= mid)count++;
    //     }
    //     return count;
    // }
    int findDuplicate(vector<int>& nums) {
    int slow = nums[0];
    int fast = nums[0];

    slow = nums[slow];
    fast = nums[nums[fast]];
    while(slow != fast)
    {
        slow = nums[slow];
        fast = nums[nums[fast]];
    }  
    slow = nums[0];
    while(slow != fast)
    {
        slow = nums[slow];
        fast = nums[fast];
    }  
    // slow = nums[0];
    return slow;

    // binary search 
    // NlogN
    // int left = 0;
    // int right = nums.size();
    // int duplicate;
    // while(left <= right)
    // {
    //     int mid = left + (right - left)/2;
    //     if(smallerThanMid(mid, nums) > mid)
    //     {
    //         duplicate = mid;
    //         right = mid - 1;
    //     }
    //     else
    //     {
    //         left = mid + 1;
    //     }

    // }
    // return duplicate;
      
    }
};
int main()
{
    
}
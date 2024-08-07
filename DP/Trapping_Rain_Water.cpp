#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int trap(vector<int>& height) {
    int n = height.size();
    int left = 0;   
    int right = n-1;    
    int lMaxi = INT_MIN;
    int rMaxi = INT_MIN;
    int ans = 0;
    while(left <= right)
    {
        if(height[left] <= height[right])
        {
            if(height[left] > lMaxi)
            {
                lMaxi = height[left];
            }
            else
            {
                ans += lMaxi - height[left];
                left++;
            }
        }
        else
        {
            if(height[right] > rMaxi)
            {
                rMaxi = height[right];
            }
            else
            {
                ans += rMaxi - height[right];
                right--;
            }
        }
    }
    return ans;
    }
};


// 11. Container_With_Most_Water

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int maxArea = 0;

        while(left < right)
        {
          int minHeight = min(height[left], height[right]);
          int width = right - left;
          int currArea = minHeight * width;
          maxArea = max(maxArea, currArea);

          if(height[left] < height[right])
          {
            left++;
          }
          else
          {
            right--;
          }
        }
        return maxArea;
    }
};
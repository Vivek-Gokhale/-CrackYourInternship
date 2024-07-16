// 11. Largest_Rectangle_in_Histogram


#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
    
    /*
    algo 
    1.find left smaller and right smaller for each index 
    2.calculate area for each index by right-left+1 * height[i]
    3.keep track of max area
    */
    int n = heights.size();
    vector<int> leftSmaller(n, 0);
    vector<int> rightSmaller(n, 0);
    int maxArea = INT_MIN;
    stack<int> s;
    for(int i=0; i<n; i++)
    {
        while(!s.empty() && heights[s.top()] >= heights[i])
        {
            s.pop();
        }
        if (s.empty())
          leftSmaller[i] = 0;
        else
          leftSmaller[i] = s.top() + 1;
       
        s.push(i);
    }

    while(!s.empty())
    s.pop();

    for(int i=n-1; i>=0; i--)
    {
        while(!s.empty() && heights[s.top()] >= heights[i])
        {
            s.pop();
        }
        if (s.empty())
          rightSmaller[i] = n-1;
        else
          rightSmaller[i] = s.top() - 1;
        
        s.push(i);
    }
    for(int i=0; i<n; i++)
    {
        maxArea = max(maxArea,( rightSmaller[i] - leftSmaller[i] + 1 ) * heights[i]);
    }
    return maxArea;

    }
};
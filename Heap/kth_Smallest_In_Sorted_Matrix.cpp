#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int left = matrix[0][0];
        int high = matrix[n-1][n-1];
        while(left <= high)
        {
            int mid = left + (high - left) /2;
            int cnt = 0;
            for(int i=0; i<n; i++)
            {
                cnt += upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
            }
            if(cnt < k)
            {
                left = mid + 1;
            }
            else 
            {
                high = mid - 1;
            }
        }
        return left;
    }
};
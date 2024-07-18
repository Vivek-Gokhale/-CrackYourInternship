// 11. Remove Boxes


#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int dp[101][101][101];

    int Helper(vector<int>& boxes, int i, int j, int cnt) {
        if (i > j) return 0;
        if (dp[i][j][cnt] != -1) return dp[i][j][cnt];
        
        // Combine all consecutive boxes of the same color
        int i0 = i, cnt0 = cnt;
        while (i + 1 <= j && boxes[i] == boxes[i + 1]) {
            i++;
            cnt++;
        }
        
        // Option 1: Remove the first block of boxes (i.e., all consecutive boxes of the same color)
        int ans = (cnt + 1) * (cnt + 1) + Helper(boxes, i + 1, j, 0);
        
        // Option 2: Try to merge non-consecutive boxes of the same color
        for (int k = i + 1; k <= j; k++) {
            if (boxes[k] == boxes[i]) {
                ans = max(ans, Helper(boxes, i + 1, k - 1, 0) + Helper(boxes, k, j, cnt + 1));
            }
        }
        
        return dp[i0][j][cnt0] = ans;
    }

    int removeBoxes(vector<int>& boxes) {
        memset(dp, -1, sizeof(dp));
        return Helper(boxes, 0, boxes.size() - 1, 0);
    }
};

#include <vector>
using namespace std;

class Solution {
public:
    int Helper(int l, int h, vector<vector<int>>& memo) {
        if (l > h) return 1;  // Changed from 0 to 1, since an empty tree is also a valid BST
        if (memo[l][h] != -1) return memo[l][h];

        int ans = 0;
        for (int i = l; i <= h; i++) {
            int leftBST = Helper(l, i - 1, memo);
            int rightBST = Helper(i + 1, h, memo);
            ans += leftBST * rightBST;
        }
        return memo[l][h] = ans;
    }

    int numTrees(int n) {
        if (n == 0) return 0;
        vector<vector<int>> memo(n + 1, vector<int>(n + 1, -1));
        return Helper(1, n, memo);
    }
};

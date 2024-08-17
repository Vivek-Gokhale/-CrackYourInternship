#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int mini;
    int n1;
    int n2;

    void Helper(int idx, std::vector<int>& arr, int s1Sum, int s2Sum, int s1Cnt, int s2Cnt, int n) {
        if (idx == n) {
            if (abs(s1Sum - s2Sum) < mini) {
                mini = abs(s1Sum - s2Sum);
                n1 = s1Sum;
                n2 = s2Sum;
            }
            return; // End recursion when idx reaches n
        }

        // Include the current element in the first subset if its size is less than (n + 1) / 2
        if (s1Cnt < (n + 1) / 2) {
            Helper(idx + 1, arr, s1Sum + arr[idx], s2Sum, s1Cnt + 1, s2Cnt, n);
        }

        // Include the current element in the second subset if its size is less than (n + 1) / 2
        if (s2Cnt < (n + 1) / 2) {
            Helper(idx + 1, arr, s1Sum, s2Sum + arr[idx], s1Cnt, s2Cnt + 1, n);
        }
    }

    std::vector<std::vector<int>> minDifference(std::vector<int>& arr, int n) {
        mini = 1e9; // Initialize to a large value
        n1 = n2 = 0; // Initialize the subset sums
        Helper(0, arr, 0, 0, 0, 0, n);
        
        // Returning the subsets that have the minimum difference
     return {{}};
    }
};
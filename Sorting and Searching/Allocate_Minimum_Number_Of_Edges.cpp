// Allocate Minimum number of edges

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to find minimum number of pages.
    int countStudents(int arr[], int pages, int n) {
        int std = 1;
        int pageCnt = 0;
        for (int i = 0; i < n; i++) {
            if (pageCnt + arr[i] <= pages) {
                pageCnt += arr[i];
            } else {
                std++;
                pageCnt = arr[i];
            }
        }
        return std;
    }

    long long findPages(int n, int arr[], int m) {
        if (m > n) return -1;
        long long ans = -1; // Initialize with -1 to handle cases where no valid answer is found
        int low = *max_element(arr, arr + n);
        int high = accumulate(arr, arr + n, 0);
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int stdCnt = countStudents(arr, mid, n);
            if (stdCnt <= m) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};
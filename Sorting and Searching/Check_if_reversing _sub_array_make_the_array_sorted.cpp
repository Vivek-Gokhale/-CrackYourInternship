// Check if reversing a sub array make the array sorted


#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

bool canReverseSubarraySort(std::vector<int>& arr) {
    int n = arr.size();
    int startIdx = INT_MAX, endIdx = INT_MIN;

    std::vector<int> temp = arr;
    std::sort(temp.begin(), temp.end());

    for (int i = 0; i < n; i++) {
        if (arr[i] != temp[i]) {
            startIdx = std::min(startIdx, i);
            endIdx = std::max(endIdx, i);
        }
    }

    if (startIdx == INT_MAX || endIdx == INT_MIN) {
        // The array is already sorted
        return true;
    }

    std::reverse(arr.begin() + startIdx, arr.begin() + endIdx + 1);

    return arr == temp;
}

int main() {
    std::vector<int> arr = {1, 3, 5, 4, 2, 6};
    if (canReverseSubarraySort(arr)) {
        std::cout << "Yes, reversing a subarray will sort the array." << std::endl;
    } else {
        std::cout << "No, reversing a subarray will not sort the array." << std::endl;
    }
    return 0;
}

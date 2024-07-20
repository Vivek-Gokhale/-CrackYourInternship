// 121. Radix Sort

#include <bits/stdc++.h>
using namespace std;
void countSort(int arr[], int n, int exp) {
    vector<int> output(n);  // output array
    int freq[10] = {0};     // count array to store the count of digits (0-9)

    // Store the count of occurrences of each digit in freq[]
    for (int i = 0; i < n; i++) {
        freq[(arr[i] / exp) % 10]++;
    }

    // Change freq[i] so that it contains the actual position of this digit in output[]
    for (int i = 1; i < 10; i++) {
        freq[i] += freq[i - 1];
    }

    // Build the output array
    for (int i = n - 1; i >= 0; i--) {
        output[freq[(arr[i] / exp) % 10] - 1] = arr[i];
        freq[(arr[i] / exp) % 10]--;
    }

    // Copy the output array to arr[], so that arr[] now contains sorted numbers
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

// Main function to implement radix sort
void radixSort(int arr[], int n) {
    // Find the maximum number to know the number of digits
    int maxi = *max_element(arr, arr + n);

    // Do counting sort for every digit. Note that instead of passing the digit number,
    // exp is passed. exp is 10^i where i is the current digit number
    for (int exp = 1; maxi / exp > 0; exp *= 10) {
        countSort(arr, n, exp);
    }
}
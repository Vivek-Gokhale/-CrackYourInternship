
// Aggresive cows

#include <bits/stdc++.h>
using namespace std;


bool isFeasible(vector<int>& stalls, int n, int c, int dist) {
    int count = 1; // Place the first cow in the first stall
    int last_position = stalls[0];

    for (int i = 1; i < n; ++i) {
        if (stalls[i] - last_position >= dist) {
            count++;
            last_position = stalls[i];
            if (count == c) {
                return true;
            }
        }
    }
    return false;
}

int largestMinDistance(vector<int>& stalls, int n, int c) {
    sort(stalls.begin(), stalls.end());

    int left = 1;
    int right = stalls[n-1] - stalls[0];
    int result = 0;

    while (left <= right) {
        int mid = left + (left + right) / 2;

        if (isFeasible(stalls, n, c, mid)) {
            result = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return result;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, c;
        cin >> n >> c;

        vector<int> stalls(n);
        for (int i = 0; i < n; ++i) {
            cin >> stalls[i];
        }

        cout << largestMinDistance(stalls, n, c) << endl;
    }

    return 0;
}

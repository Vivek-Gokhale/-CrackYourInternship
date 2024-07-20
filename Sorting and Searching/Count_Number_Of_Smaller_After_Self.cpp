// Count Numberof smaller after self
#include <vector>
using namespace std;

class Solution {
public:
    void merge(int s, int e, int mid, vector<pair<int, int>> &idxMap, vector<int> &freq) {
        int N = mid - s + 1;
        int M = e - mid;
        vector<pair<int, int>> temp(N + M);
        int k = 0;
        int i = s;
        int j = mid + 1;
        
        while (i <= mid && j <= e) {
            if (idxMap[i].first <= idxMap[j].first) {
                // Update frequency for elements on the left side
                temp[k++] = idxMap[j++];
                
            } else {
                freq[idxMap[i].second] += e-j+1;
                temp[k++] = idxMap[i++];
            }
        }
        
        while (i <= mid) {
            
            temp[k++] = idxMap[i++];
        }
        
        while (j <= e) {
            temp[k++] = idxMap[j++];
        }
        
        k = 0;
        for (int i = s; i <= e; i++) {
            idxMap[i] = temp[k++];
        }
    }

    void mergeSort(int left, int right, vector<pair<int, int>> &idxMap, vector<int> &freq) {
        if (left >= right) return;

        int mid = left + (right - left) / 2;
        mergeSort(left, mid, idxMap, freq);
        mergeSort(mid + 1, right, idxMap, freq);
        merge(left, right, mid, idxMap, freq);
    }

    vector<int> countSmaller(vector<int>& nums) {
        vector<pair<int, int>> idxMap;
        int n = nums.size();
        vector<int> freq(n, 0);
        
        for (int i = 0; i < n; i++) {
            idxMap.push_back({nums[i], i});
        }
        
        mergeSort(0, n - 1, idxMap, freq);
        return freq;
    }
};

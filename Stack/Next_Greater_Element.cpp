// 121. Add Binary

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
		stack<int> stack;
        unordered_map<int, int> map;
    
        for (int i = 0; i < nums2.size(); i++) {
            while (!stack.empty() && nums2[i] > stack.top()) {
				map[stack.top()] = nums2[i];
				stack.pop();
			}
            stack.push(nums2[i]);
        }
    
        while (!stack.empty()) {
			map[stack.top()] = -1;
			stack.pop();
		}
           
    
        vector<int> res(nums1.size());
        for (int i = 0; i < nums1.size(); i++) {
            res[i] = map[nums1[i]];
        }
                                            
        return res;
	}
};
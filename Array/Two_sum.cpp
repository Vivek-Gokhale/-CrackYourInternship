// Two_sum 

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        unordered_map<int, int> umap;
        vector<int> indexVector;

        for(int i=0; i<nums.size(); i++)
        {
            int curr = nums[i];
            int x = target - curr;
            if(umap.find(x) != umap.end())
            {
                indexVector.push_back(umap.at(x));
                indexVector.push_back(i);
            }
            else
            {
                umap[curr] = i;
            }
        }
        return indexVector;
    }
};
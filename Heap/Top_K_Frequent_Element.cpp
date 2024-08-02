#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> umap;
        for(auto it : nums)
        umap[it]++;
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for(auto it : umap)
        {
            pq.push({it.second, it.first});
            if(pq.size() > k)
            pq.pop();
        }      
        vector<int> ans;
        while(!pq.empty())
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};
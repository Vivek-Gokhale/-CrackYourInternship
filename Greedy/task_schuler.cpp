#include<bits/stdc++.h> 
using namespace std;
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
    vector<int> freqMap(26,0);
    for(auto t : tasks)
    {
        freqMap[t-'A']++;
    }   
    priority_queue<int> pq; 
    for(auto it : freqMap)
    {
        if(it > 0)
        pq.push(it);
    }
    int ans = 0;
    while(!pq.empty())
    {
        vector<int> temp;
        for(int i=1; i<=n+1; i++)
        {
            if(!pq.empty())
            {
                int freq = pq.top();
                freq--;
                pq.pop();
                temp.push_back(freq);
            }
            
        }
        for(auto it : temp)
        {
            if(it > 0)
            pq.push(it);
        }
        if(pq.empty())
        {
            ans += temp.size();
        }
        else
        {
            ans += n+1;
        }
    }
    return ans;
    }
};
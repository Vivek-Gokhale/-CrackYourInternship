#include<bits/stdc++.h> 
using namespace std; 
class Solution {
public:
    int minDeletions(string s) {
        vector<int> freq(26, 0);
        for(auto it : s)
        freq[it-'a']++;
        priority_queue<int> pq;
        for(int i=0; i<26; i++)
        {
            if(freq[i] > 0)
            pq.push(freq[i]);
        }
        if(pq.size() == 1)return 0;
        int cnt = 0;
        while(pq.size() > 1)
        {
            int f1 = pq.top();
            pq.pop();
            int f2 = pq.top();
            pq.pop();
            if(f1 == f2)
            {
                cnt++;
                if(f1 - 1 > 0)
                pq.push(f1-1);
                pq.push(f2);
            }
            else
            {
                pq.push(min(f1,f2));
            }
        }
    return cnt;
    }
};
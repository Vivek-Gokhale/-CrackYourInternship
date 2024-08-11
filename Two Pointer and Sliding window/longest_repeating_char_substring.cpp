#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> mp(26, 0);
        int i=0, j=0, maxLen = 0, maxFreq = 0;
        while(j < s.size())
        {
            mp[s[j]-'A']++;
            maxFreq = max(maxFreq, mp[s[j]-'A']);
            while((j-i+1)-maxFreq > k)
            {
                mp[s[i]-'A']--;
                maxFreq = 0;
                for(int x=0; x<26; x++)
                {
                    maxFreq = max(maxFreq, mp[x]);
                }
                i++;
            }
            maxLen = max(j-i+1, maxLen);
            j++;
        }
        return maxLen;
    }
};
// 121. FInd Duplicates Characters

#include <bits/stdc++.h>
using namespace std;
class Solution{
public:
	string removeDuplicates(string str) {
	    // code here
	    unordered_map<char, int> mp;
	    for(auto it : str)
	    mp[it]++;
	    
	    string ans = "";
	    for(int i=str.size()-1; i>=0; i--)
	    {
	        if(mp.find(str[i]) != mp.end() && mp[str[i]] > 1)
	        {
	            mp[str[i]]--;
	            if(mp[str[i]] == 1)
	            mp.erase(str[i]);
	            continue;
	        }
	        else
	        {
	            ans += str[i];
	        }
	    }
	    reverse(ans.begin(), ans.end());
	    return ans;
	}
};
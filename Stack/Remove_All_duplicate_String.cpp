
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string removeDuplicates(string s, int k) {
       stack<pair<char, int>> alphaCnt;
       int n = s.size();
       for(int i=0; i<n; i++)
       {
            if(alphaCnt.empty())
            {
                alphaCnt.push({s[i], 1});
            }
            else if(!alphaCnt.empty() && alphaCnt.top().first == s[i])
            {
                auto it = alphaCnt.top();
                alphaCnt.pop();
                alphaCnt.push({it.first, it.second+1});
                if(alphaCnt.top().second == k)alphaCnt.pop();
            }
            else 
            {
                alphaCnt.push({s[i], 1});
            }
       } 
       string ans = "";
       while(!alphaCnt.empty())
       {
           auto it = alphaCnt.top();
           alphaCnt.pop();
           char ch = it.first;
           int x = it.second;
           string temp = "";
           while(x--)
           {
                temp += ch;
           }
           ans = temp + ans;
       }
       return ans;

    }
};
// 121. Add Binary

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool backspaceCompare(string s, string t) {
    stack<char> s1;
    stack<char> t1;
    for(auto it : s)
    {
        if(it == '#')
        {
            if(!s1.empty())
            s1.pop();
        }
        else 
        {
            s1.push(it);
        }
    }
    
    for(auto it : t)
    {
        if(it == '#')
        {
            if(!t1.empty())
            t1.pop();
        }
        else 
        {
            t1.push(it);
        }
    }      
    while(!s1.empty() && !t1.empty())
    {
        if(s1.top() != t1.top())return false;
        s1.pop();
        t1.pop();
    }
    if(s1.size() == 0 && t1.size() == 0)return true;
    return false;
    }
};
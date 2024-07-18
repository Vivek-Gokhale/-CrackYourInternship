// 121. Valid Paranthesis

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isValid(string s) {
    stack<char> st;
    for(auto it : s)
    {
        if(it == '{' || it == '(' || it == '[')
        {
            st.push(it);
        }
        else 
        {
            if(!st.empty() && st.top() == '('  && it == ')')
            {
                st.pop();
            }
            else if(!st.empty() && st.top() == '{'  && it == '}')
            {
                st.pop();
            }
            
            else if(!st.empty() && st.top() == '['  && it == ']')
            {
                st.pop();
            }
            else
            {
                st.push(it);
            }
        }
    }
    if(st.empty())return true;
    return false;    
    }
};
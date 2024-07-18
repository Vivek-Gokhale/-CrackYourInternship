// 121. Basic Calculators

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int calculate(string s) {
        s += '+';
        long long ans = 0;
        int curr = 0;
        char sign = '+';
        int n = s.size();
        stack<int> st;
        for(int i=0; i<n; i++)
        {
            if(isdigit(s[i])) curr = curr * 10 + (s[i] - '0');
            else if(s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/')
            {
                if(sign == '+')
                {
                    st.push(curr);
                }else if(sign == '-')
                {
                    st.push(curr * -1);
                }else if(sign == '*')
                {
                    int num = st.top();
                    st.pop();
                    st.push(curr * num);
                }else if(sign == '/')
                {
                    int num = st.top();
                    st.pop();
                    st.push(num / curr);
                }
                curr = 0;
                sign = s[i];
            } 
        }
        while(!st.empty())
        {
            ans += st.top();
            st.pop();
        }
        return ans;
    }
};
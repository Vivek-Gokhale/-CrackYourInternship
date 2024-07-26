

#include <bits/stdc++.h>
using namespace std;
class Solution
{
    public:
    //Function to evaluate a postfix expression.
    int evaluatePostfix(string S)
    {
        // Your code here
        stack<int> st;
        for(auto it : S)
        {
            if(isdigit(it))
            {
                 st.push(it-'0');
            }
            else
            {
                int op2 = st.top();
                st.pop();
                int op1 = st.top();
                st.pop();
                int ans;
                if(it == '*')
                {
                    ans = op1 * op2;
                }
                else if(it == '+')
                {
                    ans = op1 + op2;
                }
                else if(it == '-')
                {
                    ans = op1 - op2;
                }
                else
                {
                    ans = op1 / op2;
                }
                st.push(ans);
            }
        }
        return st.top();
    }
};
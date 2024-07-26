#include <bits/stdc++.h>
using namespace std;
class Solution
{
    public:
    //Function to find maximum of minimums of every window size.
    vector <int> maxOfMin(int arr[], int n)
    {
        // Your code here
        vector<int> prevSmaller(n, -1), nextSmaller(n, n);
        stack<int> st;
        for(int i=0; i<n; i++)
        {
            while(!st.empty() && arr[i] < arr[st.top()])
            {
                nextSmaller[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        while(!st.empty())st.pop();
        for(int i=n-1; i>=0; i--)
        {
            while(!st.empty() && arr[i] < arr[st.top()])
            {
                prevSmaller[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        vector<int> ans(n+1, 0);
        for(int i=0; i<n; i++)
        {
            int k = nextSmaller[i] -  prevSmaller[i] - 1;
            ans[k] = max(ans[k], arr[i]);
        }
        for(int i=n-1; i>=1; i--)
        {
            ans[i] = max(ans[i], ans[i+1]);
        }
        vector<int> res(n);
        for(int i=1; i<=n; i++)
        {
            res[i-1] = ans[i];
        }
        return res;
        
    }
};
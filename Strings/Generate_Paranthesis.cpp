// 121.  Generate Paranthesis
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:

    void Helper(int n, int openBrackets, int closeBrackets, vector<string> &ans, string &temp)
    {
        if(openBrackets == n && closeBrackets == n)
        {
            ans.push_back(temp);
            return;
        }
        //take open bracket
        if(openBrackets < n)
        {
             temp.push_back('(');
             Helper(n, openBrackets+1, closeBrackets, ans, temp);
             temp.pop_back();
        }
       
        
        //take close braket 
        if(closeBrackets < openBrackets) 
        {
            temp.push_back(')');
            Helper(n, openBrackets, closeBrackets+1, ans, temp);
            temp.pop_back();

        }
        
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string temp = "";
        Helper(n, 0, 0, ans, temp);
        return ans;
    }
};
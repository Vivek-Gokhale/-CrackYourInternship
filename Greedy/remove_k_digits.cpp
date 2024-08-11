#include<bits/stdc++.h> 
using namespace std; 
class Solution {
public:
    string removeKdigits(string num, int k) {
        string s;
        for(auto a:num) {
            while(s.size()&&s.back()>a&&k) {
                s.pop_back();
                k--;
            }
            s.push_back(a);
        }


        while(s.size()&&k--)s.pop_back();
        int i=0;
        while(i<s.size()-1 && s[i]=='0')i++;
        if(s.size()==0)return "0";
        return s.substr(i);
    }
};
// 121.  valid Palindrome 2
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool check(string s, int i, int j)
    {
        while(i<=j)
        {
            if(s[i]!=s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    bool validPalindrome(string s) {
     int i=0; 
     int j=s.size()-1;
     int mismatchCnt = 0;
     while(i <= j)
     {
        if(s[i] != s[j])
        {
            return check(s, i+1, j) || check(s, i, j-1);
        }
        else
        {
            i++;
            j--;
        }
        
     }   
     return true;
    }
};
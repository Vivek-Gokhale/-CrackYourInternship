// 121.  Find the Index of the First Occurrence in a String
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int strStr(string haystack, string needle) {
       int len_1 = haystack.length();
        int len_2 = needle.length();
        int j = 0;
        int tmp = 0;
        int i = 0;
        int k = 0;
        while(i < len_1){
            if(haystack[i] == needle[j]){
                j++;
                i++;
            }
            else {
                j = 0;
                k++;
                i = k;
            }
            if(j == len_2){
                return i-j;
            }
        }
        return -1;
    }
};
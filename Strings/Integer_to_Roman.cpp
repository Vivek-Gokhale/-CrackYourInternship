// 121.  Integer to Roman
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string intToRoman(int num) {
       vector<string> symbols = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
       vector<int> values = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        string ans = "";
       for(int i=0; i<13; i++)
       {
            int times = num / values[i];
            while(times--)
            {
                ans += symbols[i];
            }
            num = num % values[i];
       } 
       return ans;
    }
}; 
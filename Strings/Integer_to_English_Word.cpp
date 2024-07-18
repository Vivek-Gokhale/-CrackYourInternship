// 121. Integer to English words

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string ones[20] = {"", " One", " Two", " Three", " Four", " Five", " Six", " Seven", " Eight", " Nine", " Ten", " Eleven", " Twelve", " Thirteen", " Fourteen", " Fifteen", " Sixteen", " Seventeen", " Eighteen", " Nineteen"};

    string tens[10] = {"", " Ten", " Twenty", " Thirty", " Forty", " Fifty", " Sixty", " Seventy", " Eighty", " Ninety"};
    
    string thousands[4] = {"", " Thousand", " Million", " Billion"};

    string Helper(int num)
    {
        if(num < 20)
        return ones[num];
        if(num < 100)
        return tens[num / 10] + Helper(num % 10);
        if(num < 1000)
        return Helper(num / 100) + " Hundred" + Helper(num % 100);
        for(int i=3; i>=0; i--)
        {
            if(num >= pow(1000, i))
            {
                return Helper(num / pow(1000, i)) + thousands[i] + Helper(num % (int)pow(1000, i));
            }
        }
        return "";
    }
    string numberToWords(int num) {
        if(num == 0)return "Zero";
        return Helper(num).substr(1);
        
    }
};
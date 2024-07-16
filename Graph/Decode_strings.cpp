// 11. Decode_strings


#include <bits/stdc++.h>
using namespace std;
class Solution {
public:

    string decodeHelper(string &s, int& i) {
        string answer = "";
        
        while (i < s.size() && s[i] != ']') 
        {
            if (!isdigit(s[i])) 
            {
                answer += s[i];
                i++;
            } 
            else 
            {
                int val = 0;
                while (i < s.size() && isdigit(s[i]))
                {
                    val = (val * 10 + (s[i]-'0'));
                    i++;
                }
                i++; // Move past '['
                string decodedStr = decodeHelper(s, i);
                i++; // Move past ']'
                while (val > 0) 
                {
                    answer += decodedStr;
                    val--;
                }
            }
        }
        
        return answer;
    }
    
    string decodeString(string s) {
        int i = 0;
        return decodeHelper(s, i);
        // // stack<char> stk;
        // int n = s.size();
        // for(int i = 0; i < n; i++) {
        //     if(s[i] == ']') {
        //         string temp = "";
        //         while(!stk.empty() && stk.top() != '[') {
        //             temp = stk.top() + temp;
        //             stk.pop();
        //         }
        //         stk.pop(); // Pop '['
        //         int base = 1;
        //         int num = 0;
        //         while(!stk.empty() && isdigit(stk.top())) {
        //             num += (stk.top() - '0') * base;
        //             stk.pop();
        //             base *= 10;
        //         }
        //         while(num--) {
        //             for(char ch : temp) {
        //                 stk.push(ch);
        //             }
        //         }
        //     }
        //     else {
        //         stk.push(s[i]);
        //     }
        // }
        // string result;
        // while(!stk.empty()) {
        //     result = stk.top() + result;
        //     stk.pop();
        // }
        // return result;     
    }
};
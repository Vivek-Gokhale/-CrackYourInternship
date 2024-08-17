#include <bits/stdc++.h>
using namespace std;
class Solution
{
    public:
    // Function to find the largest number after k swaps.
    void Helper(string &str, int k, int firstIdx, string &ans)
    {
        
        if (k == 0)
            return;

        int n = str.size();
        char maxChar = str[firstIdx];
        
      
        for (int i = firstIdx + 1; i < n; i++)
        {
            if (str[i] > maxChar)
                maxChar = str[i];
        }

        
        if (maxChar != str[firstIdx])
            k--;

      
        for (int i = firstIdx; i < n; i++)
        {
            if (str[i] == maxChar)
            {
                swap(str[i], str[firstIdx]);

                
                if (str > ans)
                    ans = str;

                
                Helper(str, k, firstIdx + 1, ans);

               
                swap(str[i], str[firstIdx]);
            }
        }
    }

    string findMaximumNum(string str, int k)
    {
        string ans = str;
        Helper(str, k, 0, ans);
        return ans;
    }
};
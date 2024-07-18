// 121. Text Justification

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string getLine(int i, int j, int eachSlotSpace, int extraSlotSpace, vector<string>& words, int maxWidth)
    {
        string line = "";
        for(int k = i; k < j; k++)
        {
            line += words[k];
            if(k == j - 1)
                continue;
            for(int z = 0; z < eachSlotSpace; z++)
            {
                line += " ";
            }
            if(extraSlotSpace > 0)
            {
                line += " ";
                extraSlotSpace--;
            }
        }
        while(line.size() < maxWidth)
        {
            line += " "; 
        }
        return line;
    }

    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int n = words.size();
        vector<string> ans;
        int i = 0;
        
        while(i < n)
        {
            int letterCnt = words[i].size();
            int slotCnt = 0;
            int j = i + 1;

            while(j < n && letterCnt + slotCnt + words[j].size() + 1 <= maxWidth)
            {
                letterCnt += words[j].size();
                slotCnt++;
                j++;
            }

            int remainingSpace = maxWidth - letterCnt;
            int eachSlotSpace = slotCnt == 0 ? 0 : remainingSpace / slotCnt;
            int extraSlotSpace = slotCnt == 0 ? 0 : remainingSpace % slotCnt;

            if(j == n)
            {
                eachSlotSpace = 1;
                extraSlotSpace = 0;
            }

            ans.push_back(getLine(i, j, eachSlotSpace, extraSlotSpace, words, maxWidth));
            i = j;
        }

        return ans;
    }
};

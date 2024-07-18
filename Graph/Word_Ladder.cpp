// 11. Word Ladder


#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st;
        bool is_present = false;
        int depth = 0;
        for(auto it : wordList)
        {
            if(endWord == it)
            {
                is_present = true;
            }
            st.insert(it);
        }
        if(is_present == false)return 0;
        queue<string> q;
        q.push(beginWord);
        while(!q.empty())
        {
            depth += 1;
            int siz = q.size();
            while(siz--)
            {
                auto curr = q.front();
                q.pop();
                for(int i=0; i<curr.size(); i++)
                {
                    string temp = curr;
                    for(char c='a'; c<='z'; c++)
                    {
                        temp[i] = c;
                        if(curr.compare(temp) == 0)
                        continue;
                        if(temp.compare(endWord) == 0)
                        return depth+1;
                        if(st.find(temp) != st.end())
                        {
                            q.push(temp);
                            st.erase(temp);
                        }
                    }
                }
            }
        }
        return 0;
    }
};
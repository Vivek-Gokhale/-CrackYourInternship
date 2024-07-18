// 11. Evaluate Division


#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void dfs(unordered_map<string, vector<pair<string , double>>> &mp, unordered_set<string> &visited, string s, string d, double &ans, double temp)
    {
        if(visited.find(s) != visited.end())return;
        else
        {
            visited.insert(s);
            if(s == d)
            {
                ans = temp;
                return;
            }
            else
            {
                for(auto it : mp[s])
                {
                    dfs(mp, visited, it.first, d, ans, temp * it.second);
                }
            }
        }
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, vector<pair<string , double>>> mp;
        for(int i=0; i<equations.size(); i++)
        {
            string u = equations[i][0];
            string v = equations[i][1];
            double val = values[i];
            mp[u].push_back({v, val});
            mp[v].push_back({u, 1/val});
        }
        vector<double> res;
        for(int i=0; i<queries.size(); i++)
        {
            string s = queries[i][0];
            string d = queries[i][1];
            double ans = -1.0;
            unordered_set<string> visited;
            if(mp.find(s) != mp.end())
            dfs(mp, visited, s, d, ans, 1.0);
            res.push_back(ans);
        } 
        return res;
    }
};
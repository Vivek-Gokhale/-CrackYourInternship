
#include <bits/stdc++.h>
using namespace std;
class Solution 
{
    public:
    // Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int>>& M, int n) 
    {
        stack<int> s;
        
        // Push all candidates to the stack.
        for (int i = 0; i < n; i++) {
            s.push(i);
        }
        
        // Find the potential celebrity.
        while (s.size() > 1) {
            int a = s.top();
            s.pop();
            int b = s.top();
            s.pop();
            
            // If a knows b, then a can't be a celebrity, push b.
            if (M[a][b] == 1) {
                s.push(b);
            } 
            // If a doesn't know b, then b can't be a celebrity, push a.
            else {
                s.push(a);
            }
        }
        
        // The last candidate is the potential celebrity.
        int potentialCelebrity = s.top();
        
        // Verify the candidate.
        for (int i = 0; i < n; i++) {
            // The celebrity doesn't know anyone else and everyone knows the celebrity.
            if (i != potentialCelebrity && (M[potentialCelebrity][i] == 1 || M[i][potentialCelebrity] == 0)) {
                return -1;
            }
        }
        
        return potentialCelebrity;
    }
};
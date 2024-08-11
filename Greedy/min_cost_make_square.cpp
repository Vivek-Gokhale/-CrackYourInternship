#include<bits/stdc++.h> 
using namespace std; 
class Solution {
public:
    static bool cmp(int &a, int &b) {
        return a > b;
    }

    int minimumCostOfBreaking(vector<int> X, vector<int> Y, int M, int N) {
        // Sorting the cost arrays in descending order
        sort(X.begin(), X.end(), cmp);
        sort(Y.begin(), Y.end(), cmp);
        
        int i = 0, j = 0;
        int hPiece = 1;
        int vPiece = 1;
        int totalCost = 0;
        
        // Looping through both sorted arrays to calculate the minimum cost
        while (i < Y.size() && j < X.size()) {
            if (X[j] > Y[i]) {
                totalCost += X[j] * hPiece;
                vPiece++;
                j++;
            } else {
                totalCost += Y[i] * vPiece;
                hPiece++;
                i++;
            }
        }
        
        // Adding remaining costs from Y
        while (i < Y.size()) {
            totalCost += Y[i] * vPiece;
            hPiece++;
            i++;
        }
        
        // Adding remaining costs from X
        while (j < X.size()) {
            totalCost += X[j] * hPiece;
            vPiece++;
            j++;
        }
        
        return totalCost;
    }
};

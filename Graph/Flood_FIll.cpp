// 11. Flood_FIll


#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void Helper(vector<vector<int>>& image, int sr, int sc, int color, int pixel) {
        if(sr < 0 || sc < 0 || sr >= image.size() || sc >= image[0].size()) return;
        if(image[sr][sc] != pixel) return;
        
        image[sr][sc] = color;
        
        Helper(image, sr-1, sc, color, pixel); // up
        Helper(image, sr+1, sc, color, pixel); // down
        Helper(image, sr, sc-1, color, pixel); // left
        Helper(image, sr, sc+1, color, pixel); // right
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int pixel = image[sr][sc];
        if(pixel != color) {
            Helper(image, sr, sc, color, pixel);
        }
        return image;
    }
};

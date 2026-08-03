class Solution {
public:

    void dfs(vector<vector<int>> &image, int r, int c, int prevcolor, int color){
        int m = image.size();
        int n = image[0].size();
        if(r<0 || c<0 || r>=m || c>=n || image[r][c] != prevcolor) return;

        image[r][c] = color;
        dfs(image,r+1,c,prevcolor,color);
        dfs(image,r,c+1,prevcolor,color);
        dfs(image,r-1,c,prevcolor,color);
        dfs(image,r,c-1,prevcolor,color);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc] == color) return image;
        dfs(image,sr,sc,image[sr][sc],color);
        return image;
    }
};
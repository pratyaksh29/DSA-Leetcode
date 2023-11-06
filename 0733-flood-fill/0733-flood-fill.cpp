class Solution {
public:
    void dfs(int i, int j,vector<vector<int>>& image,int color,int inicolor){
        
        if(i<0 || i>=image.size() || j<0 || j>= image[0].size() || image[i][j] == color || image[i][j] != inicolor){
            return;
        } 

        image[i][j] = color;
        dfs(i-1,j,image,color,inicolor);
        dfs(i+1,j,image,color,inicolor);
        dfs(i,j-1,image,color,inicolor);
        dfs(i,j+1,image,color,inicolor);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
          int inicolor = image[sr][sc];
          dfs(sr,sc,image,color,inicolor);
          return image;

    }
};
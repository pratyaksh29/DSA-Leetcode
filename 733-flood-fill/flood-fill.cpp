class Solution {
public:
    void dfs(vector<vector<int>>& image, int i, int j, int newcolor,int val){
        int row = image.size();
        int col = image[0].size();
        if(i<0||j<0||i>=row||j>=col||image[i][j]==newcolor||image[i][j]!=val){
            return;
        }
        image[i][j]=newcolor;
        dfs(image,i+1,j,newcolor,val);
        dfs(image,i,j+1,newcolor,val);
        dfs(image,i-1,j,newcolor,val);
        dfs(image,i,j-1,newcolor,val);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int val = image[sr][sc];
        dfs(image,sr,sc,color,val);
        return image;
    }
};
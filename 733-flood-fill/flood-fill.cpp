class Solution {
public:
    void dfs(vector<vector<int>>& image,int i, int j ,int prevcolor,int newcolor){
        int row = image.size();
        int col = image[0].size();
        if(i<0 || j<0 || i>=row || j>=col || image[i][j]!=prevcolor || image[i][j]==newcolor){
            return;
        }
        image[i][j]=newcolor;
        dfs(image,i,j+1,prevcolor,newcolor);
        dfs(image,i+1,j,prevcolor,newcolor);
        dfs(image,i-1,j,prevcolor,newcolor);
        dfs(image,i,j-1,prevcolor,newcolor);

    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int val = image[sr][sc];
        dfs(image,sr,sc,val,color);
        return image;


        
    }
};
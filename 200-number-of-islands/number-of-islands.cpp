class Solution {
public:
    void dfs(int row,int col,vector<vector<char>>& grid,vector<vector<int>>& vis){
        if(row<0 || col <0 || row>= grid.size() || col >= grid[0].size() || grid[row][col]=='0' || vis[row][col]==1){
            return;
        }
        vis[row][col]=1;
        dfs(row+1,col,grid,vis);
        dfs(row-1,col,grid,vis);
        dfs(row,col+1,grid,vis);
        dfs(row,col-1,grid,vis);



    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        int c =0;
        for(int i =0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1' && vis[i][j]==0){
                    c++;
                    dfs(i,j,grid,vis);
                }
            }
        }
        return c;
    }
};
class Solution {
public:
    void bfs(int row,int col,vector<vector<char>>& grid,vector<vector<int>>& vis){
        vis[row][col]=1;
        queue<pair<int,int>>q;
        q.push({row,col});
        vector<int>directions = {-1,0,1,0,-1};
        while(!q.empty()){
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            for(int k =0;k<4;k++){
                int nrow = i + directions[k];
                int ncol = j + directions[k+1];
                if(nrow>=0 && ncol >=0 && nrow<grid.size() && ncol <grid[0].size()&& grid[nrow][ncol]=='1' && vis[nrow][ncol]==0){
                    vis[nrow][ncol]=1;
                    q.push({nrow,ncol});
                }
            }
        }

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
                    bfs(i,j,grid,vis);
                }
            }
        }
        return c;
    }
};
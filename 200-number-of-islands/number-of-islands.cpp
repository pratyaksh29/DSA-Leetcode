class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        if(!row || !col){
            return 0;
        }
        vector<vector<int>>vis(row,vector<int>(col,0));
        int c = 0;
        vector<int>directions = {-1,0,1,0,-1};
        for(int i =0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]=='1' && vis[i][j]==0){
                    c++;
                    vis[i][j]=1;
                    queue<pair<int,int>>q;
                    q.push({i,j});
                    while(!q.empty()){
                        auto it = q.front();
                        q.pop();
                        for(int k =0;k<4;k++){
                            int nrow = it.first + directions[k];
                            int ncol = it.second + directions[k+1];
                            if(nrow>=0 && nrow <row && ncol >=0 && ncol<col && grid[nrow][ncol]=='1'&& vis[nrow][ncol]==0){
                                q.push({nrow,ncol});
                                vis[nrow][ncol]=1;
                            }
                        }
                    }
                }
            }
        }
        return c;
    }
};
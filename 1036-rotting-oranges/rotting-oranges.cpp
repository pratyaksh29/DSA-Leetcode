class Solution {
public://put all rotten oranges in the queue where u also store the respective time // mark them as visited // do a bfs // then check if fresh still exist -> if yes then return -1 otherwise return max time
    int orangesRotting(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        if(!row || !col){
            return 0;
        }
        queue<pair<pair<int,int>,int>>q;
        vector<vector<int>>vis(row,vector<int>(col,0));
        for(int i =0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                    vis[i][j]=1;
                }
            }
        }
        int time=0;
        vector<int>dir = {-1,0,1,0,-1};
        while(!q.empty()){
            int m = q.front().first.first;
            int n = q.front().first.second;
            int t = q.front().second;
            q.pop();
            time = max(time,t);
            for(int k =0;k<4;k++){
                int nrow = m+dir[k];
                int ncol = n + dir[k+1];
                if(nrow>=0&&ncol>=0&&nrow<row&&ncol<col&&vis[nrow][ncol]==0&&grid[nrow][ncol]==1){
                    vis[nrow][ncol]=1;
                    q.push({{nrow,ncol},t+1});
                }
            }
        }

        for(int i =0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]==1&&vis[i][j]==0){
                    return -1;
                }
            }
        }
        return time;
    }
};
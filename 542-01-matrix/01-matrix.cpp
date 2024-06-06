class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int row = mat.size();
        int col = mat[0].size();

        queue<pair<pair<int,int>,int>>q;
        vector<vector<int>>vis(row,vector<int>(col,0));
        vector<vector<int>>dis(row,vector<int>(col,0));

        for(int i =0;i<row;i++){
            for(int j =0;j<col;j++){
                if(mat[i][j]==0){
                    q.push({{i,j},0});
                    vis[i][j]=1;
                }
            }
        }
        vector<int>dir={-1,0,1,0,-1};

        while(!q.empty()){
            int m = q.front().first.first;
            int n = q.front().first.second;
            int step = q.front().second;
            q.pop();

            dis[m][n]=step;

            for(int i =0;i<4;i++){
                int nrow = m + dir[i];
                int ncol = n+dir[i+1];
                if(nrow>=0&&ncol>=0&&nrow<row&&ncol<col&&vis[nrow][ncol]==0){
                    vis[nrow][ncol]=1;
                    q.push({{nrow,ncol},step+1});
                }
            }
        }
        return dis;
    }
};
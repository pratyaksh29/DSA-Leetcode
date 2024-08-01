class Solution {
public:
    void dfs(int i, int j , vector<vector<int>>&vis , vector<vector<char>>& board){
        int row = board.size();
        int col = board[0].size();
        if(!row || !col){
            return;
        }
        if(i>=row || j>=col || i<0 || j<0 || vis[i][j]==1 || board[i][j]=='X'){
            return;
        }
        vis[i][j]=1;
        dfs(i+1,j,vis,board);
        dfs(i-1,j,vis,board);
        dfs(i,j+1,vis,board);
        dfs(i,j-1,vis,board);
    }
    void solve(vector<vector<char>>& board) {
        int row = board.size();
        int col = board[0].size();
        vector<vector<int>>vis(row,vector<int>(col,0));
        for(int i =0;i<row;i++){ //column left
            if(board[i][0]=='O'&& vis[i][0]==0){
                dfs(i,0,vis,board);
            }
            if(board[i][col-1]=='O' && vis[i][col-1]==0){
                dfs(i,col-1,vis,board);
            }
        }
        for(int j=0;j<col;j++){
            if(board[0][j]=='O' && vis[0][j]==0){
                dfs(0,j,vis,board);
            }
            if(board[row-1][j]=='O' && vis[row-1][j]==0){
                dfs(row-1,j,vis,board);
            }
        }

        for(int i =0;i<row;i++){
            for(int j=0;j<col;j++){
                if(!vis[i][j] && board[i][j]=='O'){
                    board[i][j]='X';
                }
            }
        }
    }
};
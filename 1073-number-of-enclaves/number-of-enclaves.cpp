class Solution {
public:
    void dfs(int i, int j, vector<vector<int>>& board, vector<vector<int>>& vis) {
        int row = board.size();
        int col = board[0].size();
        if (!row || !col) {
            return;
        }
        vis[i][j] = 1;
        vector<int> dir = {-1, 0, 1, 0, -1};
        for (int k = 0; k < 4; k++) {
            int nrow = i + dir[k];
            int ncol = j + dir[k + 1];
            if (nrow >= 0 && ncol >= 0 && nrow < row && ncol < col && vis[nrow][ncol] == 0 && board[nrow][ncol] == 1) {
                dfs(nrow, ncol, board, vis);
            }
        }
    }

    void solve(vector<vector<int>>& board,int &c) {
        int row = board.size();
        int col = board[0].size();
        vector<vector<int>> vis(row, vector<int>(col, 0));

        // Traverse the first and last row
        for (int j = 0; j < col; j++) {
            if (board[0][j] == 1 && vis[0][j] == 0) {
                dfs(0, j, board, vis);
            }
            if (board[row - 1][j] == 1 && vis[row - 1][j] == 0) {
                dfs(row - 1, j, board, vis);
            }
        }

        // Traverse the first and last column
        for (int i = 0; i < row; i++) {
            if (board[i][0] == 1 && vis[i][0] == 0) {
                dfs(i, 0, board, vis);
            }
            if (board[i][col - 1] == 1 && vis[i][col - 1] == 0) {
                dfs(i, col - 1, board, vis);
            }
        }

        // Replace unvisited 1s with 'X'
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (board[i][j] == 1 && vis[i][j] == 0) {
                    c++;
                }
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int c = 0;
        solve(grid,c);
        return c;
    }
};
class Solution {
public:
    void dfs(int i,int j,vector<vector<char>>& grid){
        int row = grid.size();
        int col = grid[0].size();
        
        if(i<0 || i>=row || j<0 || j>= col || grid[i][j]=='0'){
            return;
        }
        grid[i][j]='0';
        dfs(i+1,j,grid);
        dfs(i-1,j,grid);
        dfs(i,j+1,grid);
        dfs(i,j-1,grid);
        
    }

    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        if(!row || !col){
            return 0;
        }
        int count =0;
        for(int i =0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]=='1'){
                    count++;
                    dfs(i,j,grid);
                }
            }
        }
        return count;
    }
};














// class Solution {
// public:
//     void dfs(int i,int j,vector<vector<char>>&grid){
//         if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size() || grid[i][j]=='0')
//             return;
//         grid[i][j] = '0';
//         dfs(i+1,j,grid);
//         dfs(i-1,j,grid);
//         dfs(i,j+1,grid);
//         dfs(i,j-1,grid);
//     }
    
//     int numIslands(vector<vector<char>>& grid) {
//         int row = grid.size();
//         int col = grid[0].size();
//         int count = 0;
//         for(int i=0;i<row;i++){
//             for(int j=0;j<col;j++){
//                 if(grid[i][j]=='1'){
//                     count++;
//                     dfs(i,j,grid);
//                 }
//             }
//         }
//         return count;
//     }
// };




// class Solution {
// private:
//     void bfs(int row, int col, vector<vector<int>>& vis, vector<vector<char>>& grid) {
//         int n = grid.size();
//         int m = grid[0].size();
//         vis[row][col] = 1;
//         queue<pair<int, int>> q;
//         q.push({row, col});
//         while (!q.empty()) {
//             int r = q.front().first;
//             int c = q.front().second;
//             q.pop();
//             // Traverse the neighbors
//             int dr[] = {-1, 0, 1, 0};
//             int dc[] = {0, -1, 0, 1};
//             for (int i = 0; i < 4; i++) {
//                 int nrow = r + dr[i];
//                 int ncol = c + dc[i];
//                 if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] && grid[nrow][ncol] == '1') {
//                     vis[nrow][ncol] = 1;
//                     q.push({nrow, ncol});
//                 }
//             }
//         }
//     }

// public:
//     int numIslands(vector<vector<char>>& grid) {
//         int n = grid.size();
//         if (n == 0) return 0;
//         int m = grid[0].size();
//         vector<vector<int>> vis(n, vector<int>(m, 0));
//         int cnt = 0;
//         for (int row = 0; row < n; row++) {
//             for (int col = 0; col < m; col++) {
//                 if (!vis[row][col] && grid[row][col] == '1') {
//                     cnt++;
//                     bfs(row, col, vis, grid);
//                 }
//             }
//         }
//         return cnt;
//     }
// };

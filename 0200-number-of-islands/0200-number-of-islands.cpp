



class Solution {
private:
    void bfs(int row, int col, vector<vector<int>>& vis, vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vis[row][col] = 1; //mark this current node as visited
        queue<pair<int, int>> q;
        q.push({row, col});
        while (!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            // Traverse the neighbors
            vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
            for (auto it : directions) { //iterating thru the directions vector
                int nrow = r +  it.first; //adding the new directions to it
                int ncol = c + it.second;
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] && grid[nrow][ncol] == '1') {
                    vis[nrow][ncol] = 1;
                    q.push({nrow, ncol});
                }
            }
        }
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        if (n == 0) return 0;
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));//this is how u initiate a 2d vector
        int cnt = 0;
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < m; col++) {
                if (!vis[row][col] && grid[row][col] == '1') { //if it hasnt been visited and if its a land then increment count and do a bfs for its neighbours
                    cnt++;
                    bfs(row, col, vis, grid);
                }
            }
        }
        return cnt;
    }
};

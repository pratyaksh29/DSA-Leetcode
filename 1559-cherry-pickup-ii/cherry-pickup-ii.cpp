class Solution {
private:
    int f(int i, int j1, int j2, vector<vector<int>>& grid, vector<vector<vector<int>>>& dp) {
        int row = grid.size();
        int col = grid[0].size();

        if (dp[i][j1][j2] != -1) {
            return dp[i][j1][j2];
        }

        if (j1 < 0 || j1 >= col || j2 < 0 || j2 >= col) {
            return -1e9;
        }
        if (i == row - 1) {
            if (j1 == j2) {
                return grid[i][j1];
            }
            else {
                return grid[i][j1] + grid[i][j2];
            }
        }

        // Explore all paths that Alice and Bob can go together
        int maxi = -1e9;
        for (int dj1 = -1; dj1 <= 1; dj1++) {
            for (int dj2 = -1; dj2 <= 1; dj2++) {
                if (j1 + dj1 >= 0 && j1 + dj1 < col && j2 + dj2 >= 0 && j2 + dj2 < col) {
                    if (j1 == j2) {
                        maxi = max(maxi, grid[i][j1] + f(i + 1, j1 + dj1, j2 + dj2, grid, dp));
                    }
                    else {
                        maxi = max(maxi, grid[i][j1] + grid[i][j2] + f(i + 1, j1 + dj1, j2 + dj2, grid, dp));
                    }
                }
            }
        }
        return dp[i][j1][j2] = maxi;
    }

public:
    int cherryPickup(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        vector<vector<vector<int>>> dp(row, vector<vector<int>>(col, vector<int>(col, -1)));
        return f(0, 0, col - 1, grid, dp);
    }
};

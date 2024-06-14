class Solution {
public:
    void dfs(int i, int j, vector<vector<int>>& vis, vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        vis[i][j] = 1;
        vector<int> dir = {-1, 0, 1, 0, -1};
        for (int k = 0; k < 4; k++) {
            int nrow = i + dir[k];
            int ncol = j + dir[k + 1];
            if (nrow >= 0 && ncol >= 0 && nrow < m && ncol < n && vis[nrow][ncol] != 1 && heights[nrow][ncol]>=heights[i][j]) {
                dfs(nrow, ncol, vis, heights);
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<int>> pacific(m, vector<int>(n, 0));
        vector<vector<int>> atlantic(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++) { // going through the first and last column
            dfs(i, 0, pacific, heights);
            dfs(i, n - 1, atlantic, heights);
        }
        for (int j = 0; j < n; j++) { // going through the first and last row
            dfs(0, j, pacific, heights);
            dfs(m - 1, j, atlantic, heights);
        }
        vector<vector<int>> ans;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (pacific[i][j] && atlantic[i][j]) {
                    ans.push_back({i, j});
                }
            }
        }
        return ans;
    }
};

class Solution {
public:
    int f(int i, int j, vector<vector<int>>& triangle, vector<vector<int>>& dp) {
        if (i < 0 || j < 0 || j>i) {
            return INT_MAX;  // Return a high value for out-of-bounds to ensure it doesn't get chosen as minimum
        }
        if (i == 0 && j == 0 ) {
            return triangle[i][j];  // Base case
        }
        if (dp[i][j] != -1) {
            return dp[i][j];  // Return memoized result if available
        }

        int upleft = INT_MAX, upright = INT_MAX;
        if (i - 1 >= 0 && j - 1 >= 0) {
            upleft = f(i - 1, j - 1, triangle, dp);  // Move from top-left
        }
        if (i - 1 >= 0) {
            upright = f(i - 1, j, triangle, dp);  // Move from top
        }

        return dp[i][j] = triangle[i][j] + min(upleft, upright);  // Memoize and return the result
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        int row = triangle.size();
        int col = triangle[row - 1].size();
        vector<vector<int>> dp(row, vector<int>(col, -1));

        // Find the minimum path sum from the bottom row to the top
        int minTotal = INT_MAX;
        for (int j = 0; j < col; j++) {
            minTotal = min(minTotal, f(row - 1, j, triangle, dp));
        }

        return minTotal;
    }
};

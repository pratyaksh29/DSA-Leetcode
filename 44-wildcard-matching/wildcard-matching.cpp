class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        dp[0][0] = 1;

        for (int j = 1; j <= m; j++) {
            if (p[j - 1] == '*') { // use j-1 instead of j
                dp[0][j] = dp[0][j - 1];
            } else {
                dp[0][j] = 0;
            }
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s[i - 1] == p[j - 1] || p[j - 1] == '?') { // use i-1 and j-1 instead of i and j
                    dp[i][j] = dp[i - 1][j - 1];
                } else if (p[j - 1] == '*') { // use j-1 instead of j
                    dp[i][j] = dp[i - 1][j] || dp[i][j - 1]; // use logical OR instead of +
                } else {
                    dp[i][j] = 0;
                }
            }
        }
        return dp[n][m];
    }
};

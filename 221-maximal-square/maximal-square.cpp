class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size();
        if (n == 0) return 0;
        int m = matrix[0].size();
        vector<vector<int>>dp(n,vector<int>(m,0));
        for(int i =0;i<n;i++){
            for(int j=0;j<m;j++){
                if (i==0||j==0||matrix[i][j] == '0') { //got stuck here -> if it is not 1 then we wont pick it
                    dp[i][j] = matrix[i][j] - '0';
                }
                else{ //if 1 -> we will pick
                    dp[i][j] = 1+ min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]));
                } 
            }
        }
        int maxi = INT_MIN;
        for(int i =0;i<n;i++){
            for(int j=0;j<m;j++){
                maxi=max(maxi,dp[i][j]); // count the squares with all 1s
            }
        }
        return maxi*maxi;
    }
};
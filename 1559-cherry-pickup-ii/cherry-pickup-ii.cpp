class Solution {
public:
    int f(int i, int j1, int j2, vector<vector<int>>& grid, vector<vector<vector<int>>>& dp){
        int n = grid.size();
        int m = grid[0].size();
        if(j1<0 || j2<0 || j1>=m || j2>=m){
            return INT_MIN;
        }
        if(i==grid.size()-1){
            if(j1==j2){
                return grid[i][j1];
            }
            else{
                return grid[i][j1] + grid[i][j2];
            }
        }
        if(dp[i][j1][j2] != -1){
            return dp[i][j1][j2];
        }
        int ans=INT_MIN;
        for(int dj1 = -1;dj1<=1;dj1++){
            for(int dj2 = -1;dj2<=1;dj2++){
                int value = 0;
                if(j1==j2){
                    value= grid[i][j1] + f(i+1,j1+dj1,j2+dj2,grid,dp);
                }
                else{
                    value= grid[i][j1] + grid[i][j2] + f(i+1,j1+dj1,j2+dj2,grid,dp);
                }
                ans = max(ans,value);

            }
        }
        return dp[i][j1][j2]=ans;

    }
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));
        return f(0,0,m-1,grid,dp);

    }
};
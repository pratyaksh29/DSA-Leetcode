class Solution {
private:
    int f(int i, int j,vector<int>& cuts,vector<vector<int>>&dp){
        if(i>j){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int mini= 1e9;
        for(int ind =i;ind<=j;ind++){
            int cost = cuts[j+1]-cuts[i-1] + f(i,ind-1,cuts,dp) + f(ind+1,j,cuts,dp);
            if(cost<mini){
                mini=cost;
            }
        }
        return dp[i][j] = mini;
    }
public:
    int minCost(int n, vector<int>& cuts) {
        int c = cuts.size();
        cuts.push_back(n);
        cuts.push_back(0);
        sort(cuts.begin(),cuts.end());
        int k = cuts.size();
        vector<vector<int>>dp(k+1,vector<int>(k+1,-1));
        return f(1,c,cuts,dp);
    }
};
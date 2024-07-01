class Solution {
public:
    int f (int ind , vector<int>& cost,vector<int>& dp){
        int n = cost.size();
        if(ind>=n){
            return 0;
        }
        if(dp[ind]!=-1){
            return dp[ind];
        }
        int step1 = INT_MAX;
        int step2 = INT_MAX;
        if(ind+1<=n){
            step1 = cost[ind] + f(ind+1,cost,dp);
        }
        if(ind+2<=n){
            step2 = cost[ind] + f(ind+2,cost,dp);
        }
        return dp[ind] = min(step1,step2);
        

    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int>dp(n+1,-1);
        return min(f(0,cost,dp),f(1,cost,dp)); 
    }
};
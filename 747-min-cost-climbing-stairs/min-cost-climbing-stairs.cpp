class Solution {
public:
    int f(int n, vector<int>& cost, vector<int>& dp) {
        if (n == 0 || n==1) {
            return cost[n];
        }
        if(dp[n]){
            return dp[n];
        }
        int left = f(n - 1, cost,dp) + cost[n];
        int right = f(n - 2, cost,dp) + cost[n];

        return dp[n] = min(left, right);
    }
    
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int>dp(n+1,0);
        dp[0]=cost[0];
        dp[1]=cost[1];
        for(int i =2;i<n;i++){
            int left = cost[i] + dp[i-1];
            int right = cost[i] + dp[i-2];
            dp[i] = min(left,right);
        }
        return min(dp[n-2],dp[n-1]);
    }
};

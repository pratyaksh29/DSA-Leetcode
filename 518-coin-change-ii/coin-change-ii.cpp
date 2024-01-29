class Solution {
private:
    int f(int ind,int target,vector<int>& coins,vector<vector<int>>&dp){
        if(ind==0){
            if(target%coins[0]==0){
                return 1;
            }
            else{
                return 0;
            }
        }
        if(dp[ind][target]!=-1){
            return dp[ind][target];
        }
        int dontpick = f(ind-1,target,coins,dp);
        int pick = 0;
        if(coins[ind]<=target){
            pick = f(ind,target - coins[ind],coins,dp);
        }
        return dp[ind][target] = dontpick +pick;

    }


public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        return f(n-1,amount,coins,dp);
        
    }
};
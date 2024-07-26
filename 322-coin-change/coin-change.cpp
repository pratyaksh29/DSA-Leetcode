class Solution {
public:
    int f(int ind,int amount,vector<int>&coins,vector<vector<int>>&dp){
        if(ind == 0){
            if(amount%coins[0]==0){
                return amount/coins[0];
            }
            else{
                return 1e9;
            }
        }
        if(dp[ind][amount]!=-1){
            return dp[ind][amount];
        }

        int dontpick = f(ind-1,amount,coins,dp);
        int pick = 1e9;
        if(amount-coins[ind]>=0){
            pick = 1+ f(ind,amount-coins[ind],coins,dp);
        }
        return dp[ind][amount] = min(pick,dontpick);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>>dp(n+1,vector<int>(amount+1,-1));
        int ans = f(n-1,amount,coins,dp);
        if(ans >=1e9){
            return -1;
        }
        else{
            return ans;
        }
    }
};
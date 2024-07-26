class Solution {
public:
    int f(int ind,int amountt,vector<int>&coins,vector<vector<int>>&dp){
        if(ind == 0){
            if(amountt%coins[0]==0){
                return amountt/coins[0];
            }
            else{
                return 1e9;
            }
        }
        if(dp[ind][amountt]!=-1){
            return dp[ind][amountt];
        }

        int dontpick = f(ind-1,amountt,coins,dp);
        int pick = 1e9;
        if(amountt-coins[ind]>=0){
            pick = 1+ f(ind,amountt-coins[ind],coins,dp);
        }
        return dp[ind][amountt] = min(pick,dontpick);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>>dp(n+1,vector<int>(amount+1,1e9));

        for(int i =0;i<=amount;i++){
            if(i%coins[0]==0){
                dp[0][i]= i/coins[0];
            }
            else{
                dp[0][i]=1e9;
            }
        }

        for(int ind=1;ind<n;ind++){
            for(int amountt =0;amountt<=amount;amountt++){
                int dontpick = dp[ind-1][amountt];
                int pick = 1e9;
                if(amountt-coins[ind]>=0){
                    pick = 1+ dp[ind][amountt-coins[ind]];
                }
                dp[ind][amountt] = min(pick,dontpick);
            }
        }
        int ans = dp[n-1][amount];
        if(ans >=1e9){
            return -1;
        }
        else{
            return ans;
        }
    }
};
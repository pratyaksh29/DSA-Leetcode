class Solution {
private:
    int f(int ind,int target,vector<int>& coins,vector<vector<int>>&dp){
        if(ind == 0 ){ 
            if(target%coins[0]==0){ //stuck here too
                return target/coins[0];
            }
            else{
                return 1e9;
            }
        }
        if(target)
        if(dp[ind][target]!=-1){
            return dp[ind][target];
        }
        int notTake = 0 + f(ind-1,target,coins,dp);
        int take = 1e9;
        if(coins[ind]<=target){
            take= 1 + f(ind,target-coins[ind],coins,dp); // got stuck here
        }
        return dp[ind][target]=min(take,notTake);

//infinite supply, multiple use, etc -> whenever u take -> stand at same index
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        int ans = f(coins.size()-1,amount,coins,dp);
        if(ans>=1e9){
            return -1;
        }
        return ans;

    
        
    }
};
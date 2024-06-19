class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,0));

        for(int i =0;i<=amount;i++){
            if(i%coins[0]==0){
                dp[0][i]=i/coins[0];
            }
            else{
                dp[0][i] = 1e9;
            }
        }

        for(int ind=1;ind<n;ind++){
            for(int amoun = 0; amoun<=amount;amoun++){
                int dontpick = dp[ind-1][amoun];
                int pick = 1e9;
                if(amoun-coins[ind]>=0){
                    pick = 1+dp[ind][amoun-coins[ind]]; //dont go ind-1 as it can repeat
                }
                dp[ind][amoun] = min(pick,dontpick);
            }
        }
        int ans = dp[n-1][amount];
        if(ans>=1e9){
            return -1;
        }
        return ans;
    }
};
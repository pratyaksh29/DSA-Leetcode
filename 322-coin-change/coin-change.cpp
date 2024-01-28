class Solution {
private:
//     int f(int ind,int target,vector<int>& coins,vector<vector<int>>&dp){
//         if(ind == 0 ){ 
//             if(target%coins[0]==0){ //stuck here too ; if coins[0] are divisible by target -> return the total number it can be divided
//                 return target/coins[0];
//             }
//             else{
//                 return 1e9;
//             }
//         }
//         if(dp[ind][target]!=-1){
//             return dp[ind][target];
//         }
//         int notTake = 0 + f(ind-1,target,coins,dp);
//         int take = 1e9;
//         if(coins[ind]<=target){
//             take= 1 + f(ind,target-coins[ind],coins,dp); // got stuck here -> stay on the same index till u have to change necessarily 
//         }
//         return dp[ind][target]=min(take,notTake);

// //infinite supply, multiple use, etc -> whenever u take -> stand at same index
//     }
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,0));

        for(int i =0;i<=amount;i++){
            if(i%coins[0]==0){
                dp[0][i]= i/coins[0];
            }
            else{
                dp[0][i]=1e9;
            }
        }

        for(int i =1;i<n;i++){
            for(int j=0;j<=amount;j++){
                int dontpick = 0 + dp[i-1][j];
                int pick = 1e9;
                if(coins[i]<=j){
                    pick = 1+ dp[i][j-coins[i]];

                }
                dp[i][j]=min(pick,dontpick);
            }
        }
        int ans = dp[n-1][amount];


        if(ans>=1e9){
            return -1;
        }
        return ans;
    }
};
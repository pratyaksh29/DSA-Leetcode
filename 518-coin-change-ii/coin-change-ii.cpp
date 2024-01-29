class Solution {
// private: //memoization
//     int f(int ind,int amount,vector<int>& coins,vector<vector<int>>&dp){
//         if(ind==0){
//             if(amount%coins[0]==0){
//                 return 1; //messed up here
//             }
//             else{
//                 return 0;
//             }
//         }
//         if(dp[ind][amount]!=-1){
//             return dp[ind][amount];
//         }
//         int dontpick = f(ind-1,amount,coins,dp);
//         int pick = 0;
//         if(coins[ind]<=amount){
//             pick = f(ind,amount - coins[ind],coins,dp); //messed up here 
//         }
// //basically we wont have to write 1 + f() for pick because we arent counting the number of coins needed to reach the amount
// //we are counting the number of ways in which the amount can be reached -> that is why we return 1 in the base case instead of amount/coins[0]
//         return dp[ind][amount] = dontpick +pick;

//     }
public: //space optimization
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<int>base(amount+1,0),curr(amount+1,0);

        for(int i =0;i<=amount;i++){
            if(i%coins[0]==0){ //got stuck here
                base[i]=1;
            }
        }
        for(int i =1;i<n;i++){
            for(int t = 0;t<=amount;t++){
                int dontpick = base[t];
                int pick = 0;
                if(coins[i]<=t){
                    pick = curr[t-coins[i]];
                }
                curr[t]=pick+dontpick;
            }
            base=curr;
        }
        return base[amount];
    }
};

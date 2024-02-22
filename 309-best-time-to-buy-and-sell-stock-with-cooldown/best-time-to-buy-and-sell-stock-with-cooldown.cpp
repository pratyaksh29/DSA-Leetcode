class Solution {
// private: //memo
//     int f(int ind, int buy, int n, vector<int>&prices,vector<vector<int>>&dp){
//         if(ind >= n){ //do ind>=n instead of ind==n as we do +2 so we can go out of bounds
//             return 0;
//         }
//         if(dp[ind][buy]!=-1){
//             return dp[ind][buy];
//         }
//         if(buy){
//             return dp[ind][buy] = max(-prices[ind]+f(ind+1,0,n,prices,dp),f(ind+1,1,n,prices,dp));
//         }
//         else{ //do ind+2 after selling to account for the cooldown
//             return dp[ind][buy] = max(prices[ind]+f(ind+2,1,n,prices,dp),f(ind+1,0,n,prices,dp));
//         }

//     }
public:
    int maxProfit(vector<int>& prices) {
        int n =prices.size();
        vector<vector<int>>dp(n+2,vector<int>(2,0));
        for(int ind =n-1;ind>=0;ind--){
            dp[ind][1] = max(-prices[ind]+dp[ind+1][0],dp[ind+1][1]);
            dp[ind][0]= max(prices[ind]+dp[ind+2][1],dp[ind+1][0]);
        }
        return dp[0][1];
    }
};


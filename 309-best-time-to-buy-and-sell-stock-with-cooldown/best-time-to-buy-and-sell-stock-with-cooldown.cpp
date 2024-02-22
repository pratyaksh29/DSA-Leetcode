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
public: //tabulation
    int maxProfit(vector<int>& prices) {
        int n =prices.size();
        vector<int>front2(2,0); //for the ind+2 so this is basically current row + 2
        vector<int>front1(2,0); //current row + 1 
        vector<int>cur(2,0); //current row

        for(int ind =n-1;ind>=0;ind--){

            cur[1] = max(-prices[ind]+front1[0],front1[1]); //buy
            cur[0]= max(prices[ind]+front2[1],front1[0]); //sell

            front2 = front1; //move them upwards (as it is bottom up approach)
            front1 = cur;
        }
        return front1[1];
    }
};


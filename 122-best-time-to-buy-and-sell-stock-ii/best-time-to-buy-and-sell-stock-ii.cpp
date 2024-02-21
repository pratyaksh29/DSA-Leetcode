class Solution {
// private: //memoization
//     int f(int ind,int buy,vector<int>& prices,int n,vector<vector<int>>&dp){
//         if(ind == n){
//             return 0;
//         }
//         if(dp[ind][buy]!=-1){
//             return dp[ind][buy];
//         }
//         int profit = 0;
//         if(buy){ //buy -> pick or not pick
//             profit = max(-prices[ind] + f(ind+1,0,prices,n,dp) , f(ind+1,1,prices,n,dp));
//         }
//         else{ //sell -> pick or not pick
//             profit= max(prices[ind]+f(ind+1,1,prices,n,dp),f(ind+1,0,prices,n,dp));
//         }
//         return dp[ind][buy] = profit;
//     }
public:
    int maxProfit(vector<int>& prices) {
        int n =prices.size();
        vector<int>base(n+1,0),cur(n+1,0);

        cur[0]=0;
        cur[1]=0;


        for(int ind =n-1;ind>=0;ind--){ //make sure u run the loop backwards 
            for(int buy=0;buy<=1;buy++){
                int profit = 0;
                if(buy){ //buy -> pick or not pick
                    profit = max(-prices[ind] + cur[0] , cur[1]);
                }
                else{ //sell -> pick or not pick
                    profit = max(prices[ind] + cur[1] , cur[0]);
                }
                base[buy]=profit;
            }
            cur = base;
        }
        return cur[1];
    }
};
class Solution {
public:
//     int f(int ind,int buy,vector<int>& prices,vector<vector<int>>&dp){
//         if(ind == prices.size()){
//             return 0;
//         }
//         int profit = 0;
//         if(buy){
//             profit = max(-prices[ind],)
//         }
//     }
    int maxProfit(vector<int>& prices) {
        // int n = prices.size();
        // vector<vector<int>>dp(n,vector<int>(2,-1));
        // return f(0,1,prices,dp);
        int max_profit = 0;
        for(int i =1;i< prices.size();i++){
            if(prices[i]>prices[i-1]){
                max_profit += prices[i]-prices[i-1];
            }
        }
        return max_profit;

        
    }
};
class Solution {
private:
    int f(int ind, int transno,int k,int n, vector<int>&prices,vector<vector<int>>&dp){
        if(ind == n || transno==k*2){
            return 0;
        }

        if(dp[ind][transno]!=-1){
            return dp[ind][transno];
        }

        //buy
        if(transno%2==0){
            return dp[ind][transno] = max((-prices[ind]+f(ind+1,transno+1,k,n,prices,dp)),f(ind+1,transno,k,n,prices,dp));
        }
        //sell
        else{
            return dp[ind][transno] = max((prices[ind]+f(ind+1,transno+1,k,n,prices,dp)),f(ind+1,transno,k,n,prices,dp));
        }

    } 


public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>>dp(n+1,vector<int>(k*2,-1));
        return f(0,0,k,n,prices,dp);
    }
};
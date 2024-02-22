class Solution {
// private:
//     int f(int ind, int transno,int k,int n, vector<int>&prices,vector<vector<int>>&dp){
//         if(ind == n || transno==k*2){ //k*2 because we one transaction is equal to buy + sell ; we want to check each buy and sell's index number                             
//             return 0;                 //because if it is even then it would mean buy and if it is odd then it would mean sell
//         }
//         if(dp[ind][transno]!=-1){
//             return dp[ind][transno];
//         }
//         //buy
//         if(transno%2==0){
//             return dp[ind][transno] = max((-prices[ind]+f(ind+1,transno+1,k,n,prices,dp)),f(ind+1,transno,k,n,prices,dp));
//         }
//         //sell
//         else{
//             return dp[ind][transno] = max((prices[ind]+f(ind+1,transno+1,k,n,prices,dp)),f(ind+1,transno,k,n,prices,dp)); 
//         }//increase transno when u buy or sell otherwise keep it the same
//     } 
public: //space optimization
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<int>after(k*2+1,0);
        vector<int>cur(k*2+1,0);


        for(int ind =n-1;ind>=0;ind--){ //make sure u go backwards
            for(int transno=0;transno < (k*2);transno++){
                if(transno%2==0){
                    cur[transno] = max((-prices[ind]+after[transno+1]),after[transno]);
                }
                //sell
                else{
                    cur[transno] = max((prices[ind]+after[transno+1]),after[transno]);
                }
            }
            after = cur;
        }
        return after[0];
    }
};


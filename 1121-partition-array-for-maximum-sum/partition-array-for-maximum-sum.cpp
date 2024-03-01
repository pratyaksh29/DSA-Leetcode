class Solution {
    int f(int i,int k, vector<int>& arr,vector<int>&dp){
        int n =arr.size();
        if(i==arr.size()){ //if i crosses the size of the string then return 0
            return 0;
        }

        if(dp[i]!=-1){
            return dp[i];
        }

        int maxi=-1e9;
        int ans=0;
        for(int j=i;j<(min(n,k+i));j++){ 
            maxi = max(maxi,arr[j]);
            int sum = maxi * (j-i+1) + f(j+1,k,arr,dp);
            ans = max(ans,sum);
        }
        return dp[i] = ans;
    }
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int>dp(n+1,-1);
        return f(0,k,arr,dp);        
    }
};
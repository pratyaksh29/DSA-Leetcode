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

        for(int j=i;j<(min(n,k+i));j++){ //j will run till k limit + i or to n ; whichever exhausts first -> stuck here
            maxi = max(maxi,arr[j]); //we will store the maximum element from array
            int sum = maxi * (j-i+1) + f(j+1,k,arr,dp); //we will add that to the sum and multiple the number by the length ; 
            ans = max(ans,sum);                         //then compute rest of the array after making partition
        } //store the max sum
        return dp[i] = ans;
    }
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int>dp(n+1,0);
        dp[n]=0;
        for(int i =n-1;i>=0;i--){
            int maxi=-1e9;
            int ans=0;
            for(int j=i;j<(min(n,k+i));j++){ //j will run till k limit + i or to n ; whichever exhausts first -> stuck here
                maxi = max(maxi,arr[j]); //we will store the maximum element from array
                int sum = maxi * (j-i+1) + dp[j+1]; //we will add that to the sum and multiple the number by the length ; 
                ans = max(ans,sum);                         //then compute rest of the array after making partition
            } //store the max sum
            dp[i] = ans;

        }
        return dp[0];   
    }
};


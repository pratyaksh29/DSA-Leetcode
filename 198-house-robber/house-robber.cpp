class Solution {
public:
    int f (int ind,vector<int>& nums,vector<int>& dp){
        if(ind==0){
            return nums[ind];
        }
        if(dp[ind]!=-1){
            return dp[ind];
        }
        
        int pick = nums[ind];
        if(ind-2>=0){
            pick += f(ind-2,nums,dp);
        }
        int notpick = INT_MIN;
        if(ind-1>=0){
            notpick = f(ind-1,nums,dp);
        }
        
        return dp[ind] = max(pick,notpick);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n+1,-1);
        return f(n-1,nums,dp);
    }
};
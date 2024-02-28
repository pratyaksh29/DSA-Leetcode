class Solution {
private:
    int f(int i, int j,vector<int>& nums,vector<vector<int>>&dp){
        if(i>j){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int maxi= INT_MIN;
        for(int ind =i;ind<=j;ind++){ //go till j
            int cost = (nums[ind] * nums[j+1] * nums[i-1]) + f(i,ind-1,nums,dp) + f(ind+1,j,nums,dp); //compute the length with is nums[j+1]-nums[i-1]                                                                                      
            maxi = max(maxi,cost);                                                                //compute the left and right sides of the nums
        }
        return dp[i][j] = maxi;
    }
public:
    int maxCoins(vector<int>& nums) {

        int c = nums.size();
        nums.push_back(1);
        nums.insert(nums.begin(),1);
        // int k = nums.size();
        vector<vector<int>>dp(c+2,vector<int>(c+2,-1));
        return f(1,c,nums,dp);

        
    }
};
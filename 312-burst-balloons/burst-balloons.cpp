class Solution {
// private:
//     int f(int i, int j,vector<int>& nums,vector<vector<int>>&dp){
//         if(i>j){ //since we are doing partitions -> we can only afford i==j ; if i>j then return 0 because this means that there is no subproblem left
//             return 0;
//         }
//         if(dp[i][j]!=-1){
//             return dp[i][j];
//         }
//         int maxi= INT_MIN; 
//         for(int ind =i;ind<=j;ind++){ //go till j
//             int cost = (nums[ind] * nums[j+1] * nums[i-1]) + f(i,ind-1,nums,dp) + f(ind+1,j,nums,dp);//compute the cost which is nums[ind] * nums[j+1] * nums[i-1]                                                                                    
//             maxi = max(maxi,cost);                                                                //compute the left and right sides of the nums
//         }
//         return dp[i][j] = maxi;
//     } //note- this is technically bottom up -> we are going from the last bursted ballon to all non bursted balloons 
public: //tabulation
    int maxCoins(vector<int>& nums) {

        int c = nums.size();
        nums.push_back(1);
        nums.insert(nums.begin(),1);


        vector<vector<int>>dp(c+2,vector<int>(c+2,0)); //make the dp array with c because thats the total number of cuts
        //c+2 because we add 2 more elements
        
        for(int i=c;i>=1;i--){
            for (int j=1;j<=c;j++) {  
                if (i > j) continue; //since we have this condition ; the j loop can run from 1 to c ; otherwise we would have to change it
                                    //because j always needs to be greater than i
                int maxi= INT_MIN; 
                for (int ind = i; ind <= j; ind++) {
                // Calculate the cost for making a cut at position 'ind'.
                    int cost = (nums[ind] * nums[j+1] * nums[i-1]) + dp[i][ind-1] + dp[ind+1][j];
                    maxi = max(maxi,cost);    
                }
                dp[i][j]=maxi;
            }
        }
        return dp[1][c];
    }
};
class Solution {
// private:
//     int f(int ind,int prev, vector<int>& nums, int n,vector<vector<int>>&dp){
//         if(ind == 0){
//             return 0;
//         }
//         if(dp[ind][prev+1]!=-1){ //we will do prev+1 because prev goes from -1 to n-1 
//             return dp[ind][prev+1]; //so we need to change the index to prev +1 so its in bounds
//         }
//         int len = 0 + f(ind+1,prev,nums,n,dp); //not take

//         if(prev == -1 || nums[ind]>nums[prev]){ //if its the first element or if the sequence is increasing
//             len = max(len,1+ f(ind+1,ind,nums,n,dp));
//         }

//         return dp[ind][prev+1]=len;
//     }
public: //space optimization
    int lengthOfLIS(vector<int>& nums) {
        int n =nums.size();
        vector<int>after(n+1,0);//index & previous index
        vector<int>cur(n+1,0);

        for(int ind=n-1;ind>=0;ind--){ //go till 0 as that was the value in memo
            for(int prev = ind-1;prev>=-1;prev--){ //go till -1 as that was the value in memo
            //add prev+1 at every place where we have to update the dp as we are going to increase the prev value in the dp

                int len = 0 + after[prev+1]; //not take 

                if(prev == -1 || nums[ind]>nums[prev]){ //if its the first element or if the sequence is increasing
                    len = max(len,1+ after[ind+1]);
                }
                cur[prev+1]=len;
            }
            after = cur;
        }

        return after[0];
    }
};


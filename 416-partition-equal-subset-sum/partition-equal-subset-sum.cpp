class Solution {
// private:
//     bool subsetSum(int ind, int target,vector<int>& nums){
//         vector<bool>base(target+1,0);
//         base[0]=true;
//         if (nums[0] <= target){
//             base[nums[0]]=true;
//         }
        

//         for(int i =1;i<ind;i++){
//             vector<bool>curr(target+1,0);
//             curr[0]=true;
//             for(int j = 1; j<=target;j++){
//                 bool notTake = base[j];
//                 bool take = false;
//                 if(nums[i]<=j){
//                     take = base[j-nums[i]];
//                 }
//                 curr[j]=take || notTake;
//             }
//             base = curr;
//         }
//         return base[target];
//     }
public:

//     bool canPartition(vector<int>& nums) {
//         int n = nums.size();
//         int sum=0;
//         for(int i =0 ; i<n;i++){
//             sum+=nums[i];
//         }
//         if(n%2) return false;

//         int reqSum = sum/2;
//         return subsetSum(n,reqSum,nums);

 

        
        
//     }
// };

    bool canPartition(vector<int>& nums) {
        int n =nums.size();
        int totSum = 0;

        // Calculate the total sum of the numsay
        for (int i = 0; i < n; i++) {
            totSum += nums[i];
        }

        // If the total sum is odd, it cannot be partitioned into two equal subsets
        if (totSum % 2 == 1)
            return false;
        else {
            int k = totSum / 2;

            // Create a vector to represent the previous row of the DP table
            vector<bool> prev(k + 1, false);

            // Base case: If the target sum is 0, it can be achieved by not selecting any elements
            prev[0] = true;

            // Initialize the first row based on the first element of the numsay
            if (nums[0] <= k)
                prev[nums[0]] = true;

            // Fill in the DP table using a bottom-up approach
            for (int ind = 1; ind < n; ind++) {
                // Create a vector to represent the current row of the DP table
                vector<bool> cur(k + 1, false);
                cur[0] = true;

                for (int target = 1; target <= k; target++) {
                    // Exclude the current element
                    bool notTaken = prev[target];

                    // Include the current element if it doesn't exceed the target
                    bool taken = false;
                    if (nums[ind] <= target)
                        taken = prev[target - nums[ind]];

                    // Update the current row of the DP table
                    cur[target] = notTaken || taken;
                }

                // Set the current row as the previous row for the next iteration
                prev = cur;
            }

            // The final result is in the last cell of the previous row of the DP table
            return prev[k];
        }
    }
};
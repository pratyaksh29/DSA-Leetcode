class Solution {
private:
    bool subsetSum(int ind, int target,vector<int>& nums){
        vector<bool>base(target+1,0);
        base[0]=true;
        if (nums[0] <= target){
            base[nums[0]]=true;
        }
        
        for(int i =1;i<ind;i++){
            vector<bool>curr(target+1,0);
            curr[0]=true;
            for(int j = 1; j<=target;j++){
                bool notTake = base[j];
                bool take = false;
                if(nums[i]<=j){
                    take = base[j-nums[i]];
                }
                curr[j]=take || notTake;
            }
            base = curr;
        }
        return base[target];
    }
public:

    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum=0;
        for(int i =0 ; i<n;i++){
            sum+=nums[i];
        }

        if(sum%2==0){
            int reqSum = sum/2;
            return subsetSum(n,reqSum,nums);
        }
        else{
            return false;
        }

        

 

        
        
    }
};

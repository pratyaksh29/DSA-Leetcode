class Solution {
public:
    bool subsetsum(int ind, int k, vector<int>& nums){
        vector<bool>base(k+1,false);
        vector<bool>curr(k+1,false);
        base[0]=true;
        curr[0]=true;
        if(nums[0]==k){
            base[nums[0]]=true;
        }
        
        

        for(int i=1;i<nums.size();i++){
            for(int j=1;j<=k;j++){
                bool notpick = base[j];
                bool pick = false;
                if(j-nums[i]>=0){
                    pick = base[j-nums[i]];
                }
                curr[j]= pick || notpick;
            }
            base = curr;
        }
        return base[k];
    }
    bool canPartition(vector<int>& nums) {
        int target =0;
        for(int i =0;i<nums.size();i++){
            target += nums[i];
        }
        if(target%2==0){
            int sum = target/2;
            return subsetsum(nums.size()-1,sum,nums);
        }
        else{
            return false;
        }
        
    }
};
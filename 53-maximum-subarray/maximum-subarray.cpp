class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size()==0){
            return 0;
        }
        int sum=0;
        int maxi=INT_MIN;
        int n=nums.size();
        for(int i=0;i<n;i++){
            sum+=nums[i];
            maxi=max(maxi,sum);
            if(sum<0){ //KEEP THIS HERE NOT ABOVE
                sum=0;
            }
        }
        return maxi;
    }
};
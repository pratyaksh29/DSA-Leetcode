class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n =nums.size();
        int ans = 1e9;
        int l =0;
        int r =0;
        int sum=0;
        while(r<n){
            sum+=nums[r];
            while(sum>=target){
                ans = min(ans , r-l+1);
                sum-=nums[l];
                l++;
            }
            r++;
        }
        if(ans==1e9){
            return 0;
        }
        return ans;
        
    }
};
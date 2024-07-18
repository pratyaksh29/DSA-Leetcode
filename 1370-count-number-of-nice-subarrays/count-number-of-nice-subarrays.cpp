class Solution {
public:
    int solve(vector<int>& nums, int k) {
        int n = nums.size();
        int c=0;
        int l =0;
        int r=0;
        int sum=0;
        if(k<0){
            return 0;
        }
        while(r<n){
            sum+=nums[r]%2;
            while(sum>k){
                sum = sum - nums[l]%2;
                l++;
            }
            c+= r-l+1;
            r++;
        }
        return c;
    }

    int numberOfSubarrays(vector<int>& nums, int k){
        int n = nums.size();
        return solve(nums,k) - solve(nums,k-1);
    }
};
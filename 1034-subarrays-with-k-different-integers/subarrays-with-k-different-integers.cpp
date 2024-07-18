class Solution {
public:
    int solve(vector<int>& nums, int k){
        int r =0;
        int l=0;
        int n = nums.size();
        int ans =0;
        unordered_map<int,int>mp;
        while(r<n){
            mp[nums[r]]++;
            while(mp.size()>k){
                mp[nums[l]]--;
                if(mp[nums[l]]==0){
                    mp.erase(nums[l]);
                }
                l++;
            }
            ans+=r-l+1; //number of subarrays with atmost k different integers
            r++;
        }
        return ans;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return solve(nums,k) - solve(nums,k-1);
    }
};
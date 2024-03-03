class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n =nums.size();
        int k;
        for(k=n-2;k>=0;k--){
            if(nums[k]<nums[k+1]){
                break;
            }
        }
        if(k == -1){
            reverse(nums.begin(), nums.end());
        }
        else{
            for(int i = n-1;i>k;i--){
                if(nums[i]>nums[k]){
                    swap(nums[i],nums[k]);
                    break;
                }
            }
            reverse(nums.begin() + k + 1, nums.end());
        }
    }
};
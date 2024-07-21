class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n =nums.size();
        if(n==1){
            return nums[0];
        }
        if(nums[0]!=nums[1]){
            return nums[0];
        }
        if(nums[n-1]!=nums[n-2]){
            return nums[n-1];
        }
        int low = 1;
        int high = n-2;
        while(high>=low){
            int mid = low + (high - low) / 2;
            if(nums[mid-1]!= nums[mid] && nums[mid+1]!= nums[mid]){
                return nums[mid];
            }
            else if(nums[mid-1]==nums[mid] && mid%2==1 || mid%2==0 && nums[mid]==nums[mid+1]){ //left half
                low = mid+1;
            } 
            else{ //right hald
                high = mid-1;
            }
        }
        return -1;
    }
};
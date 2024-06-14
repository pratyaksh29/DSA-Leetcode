class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n =nums.size();
        if (nums.empty()) return 0;
        int count = 0;
        int index = 1;
        for(int i =1;i<n;i++){ 
            if(nums[i]==nums[i-1] && count >=1){
                continue;
            }
            else if(nums[i]==nums[i-1] && count ==0){
                count++;
            }
            else if(nums[i]!=nums[i-1]){
                count = 0;
            }
            nums[index++] = nums[i];
        }
        return index;
    }
};
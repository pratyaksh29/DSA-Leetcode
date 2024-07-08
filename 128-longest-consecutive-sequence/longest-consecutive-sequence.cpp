class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()<=1){
            return nums.size();
        }
        sort(nums.begin(),nums.end());
        int c =1;
        int maxi =1;
        int lastsmaller = nums[0];
        for(int i =1;i<nums.size();i++){
            if(nums[i]== nums[i-1]){
                continue;
            }
            else if(nums[i]==lastsmaller+1){
                c++;   
                lastsmaller = nums[i];
            }
            else{
                lastsmaller = nums[i];
                c=1;
            }
            maxi = max(c,maxi);
        }
        return maxi;
    }   
};
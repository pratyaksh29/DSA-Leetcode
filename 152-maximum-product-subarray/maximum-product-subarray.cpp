class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        if(n==0){
            return 0;
        }
        int prefix =1;
        int suffix = 1;
        int maxi = INT_MIN;
        for(int i =0;i<n;i++){
            if(prefix == 0){ //if either of prefix or suffix becomes 0 -> make it 1
                prefix = 1;
            }
            if(suffix == 0){
                suffix = 1;
            }
            prefix *= nums[i]; //calculate the prod from the back and from the front and find max
            suffix *= nums[n-i-1];
            maxi = max (maxi,max(prefix,suffix));
        }
        return maxi;
    }
};


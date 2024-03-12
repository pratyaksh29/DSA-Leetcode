class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        if(n==0){
            return 0;
        }
        if(n==1){
            return nums[0];
        }
        int maxi = INT_MIN;
        for(int i =0;i<n;i++){
            int prod = 1;
            for(int j =i;j<n;j++){
                prod*=nums[j];
                maxi = max(maxi , prod);
            }
        }
        return maxi;

    }
};

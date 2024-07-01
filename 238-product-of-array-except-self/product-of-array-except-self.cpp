class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n= nums.size();
        vector<int>prev(n,1),suff(n,1);

        for(int i =1;i<n;i++){
            prev[i]=prev[i-1] * nums[i-1];
        }
        for(int i =n-2;i>=0;i--){
            suff[i] = suff[i+1] * nums[i+1];
        }

        vector<int>ans(n);
        for(int i =0;i<n;i++){
            ans[i]=prev[i] * suff[i];
        }
        return ans;

    }
};
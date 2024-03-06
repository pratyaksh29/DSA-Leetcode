class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        if(n==0){
            return 0;
        }
        int ans = 0;
        for(int i =0;i<n;i++){
            int c = 0;
            for(int j=i;j<n;j++){
                c+=nums[j];
                if(c==k){
                    ans++;
                }
            }   
        }
        return ans;
    }
};
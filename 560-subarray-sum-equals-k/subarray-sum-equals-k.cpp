class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        if(n==1 && n==k){
            return 1;
        }
        unordered_map<int,int>mp; //prefix sum , count
        mp[0]=1;
        int c=0;
        int presum=0;
        for(int i =0;i<n;i++){
            presum+=nums[i];
            if(mp.find(presum-k)!=mp.end()){
                c+=mp[presum-k];
            }
            mp[presum]++;
        }
        return c;
    }
};
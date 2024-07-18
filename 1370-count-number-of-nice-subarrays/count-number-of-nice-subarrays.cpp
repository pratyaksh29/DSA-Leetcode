class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int>mp;
        int presum = 0;
        int c =0;
        mp[0]=1;
        for(int i =0;i<n;i++){
            presum += nums[i]%2;
            if(mp.find(presum-k)!=mp.end()){
                c+=mp[presum-k];
            }
            mp[presum]++;
        }
        return c;
        
    }
};
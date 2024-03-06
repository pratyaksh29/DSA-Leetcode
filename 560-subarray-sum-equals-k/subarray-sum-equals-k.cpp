class Solution {
public:
    int subarraySum(vector<int>& nums, int k) { //naive brute force approach
        int n = nums.size();
        if(n==0){
            return 0;
        }
        int preSum = 0,cnt=0;
        unordered_map<int,int>mp; //presum,count
        mp[0]=1; //sum-k,count

        for(int i =0;i<n;i++){
            preSum += nums[i];
            if(mp.find(preSum-k)!=mp.end()){
                cnt+=mp[preSum-k];
            }
            mp[preSum]++;
        }
        return cnt;
    }
};

   
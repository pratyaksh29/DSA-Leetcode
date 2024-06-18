class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>mp; //curr number, more neeeded
        int n = nums.size();
        for(int i =0;i<n;i++){
            int a = nums[i];
            int moreneeded=target-a;
            if(mp.find(moreneeded)!=mp.end()){
                return {i,mp[moreneeded]};
            }
            mp[a]=i;
        }
        return {-1,-1};

    }
};
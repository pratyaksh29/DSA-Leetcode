class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int>mp; // num, count
        vector<int>ans;
        int used;
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
            if(mp[nums[i]]>n/3 && used != nums[i]){
                ans.push_back(nums[i]);
                used = nums[i];
            }
            if(ans.size()==2){
                break;
            }
        }
        return ans;
    }
};



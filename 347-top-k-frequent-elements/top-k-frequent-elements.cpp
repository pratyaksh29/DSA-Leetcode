class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int>ans;
        unordered_map<int,int>mp;
        int n = nums.size();
        for(int i =0;i<n;i++){
            mp[nums[i]]++;
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>minh;
        for(auto i = mp.begin();i!=mp.end();i++){
            minh.push({i->second,i->first});
            if(minh.size()>k){
                minh.pop();
            }
        }
        while(!minh.empty()){
            ans.push_back(minh.top().second);
            minh.pop();
        }

        return ans;
    }
};
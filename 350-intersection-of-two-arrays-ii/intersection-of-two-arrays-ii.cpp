class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        map<int,int>mp1;
        map<int,int>mp2;

        for(int i =0;i<nums1.size();i++){
            mp1[nums1[i]]++;
        }
        for(int i =0;i<nums2.size();i++){
            mp2[nums2[i]]++;
        }

        vector<int>ans;
        for(auto it : mp1){
            int key = it.first;
            int val = it.second;
            if(mp2.find(key)!=mp2.end()){
                for(int i =0;i<min(mp2[key],mp1[key]);i++){
                    ans.push_back(key);
                }           
            }
        }
        return ans;
        
    }
};
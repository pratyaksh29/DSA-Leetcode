class Solution {
public:
    void solve(int index, vector<int>& nums,vector<int>& subsets,vector<vector<int>>& result){
        
        result.push_back(subsets);
        for(int i =index;i<nums.size();i++){
            if(i==index||nums[i]!=nums[i-1]){
                subsets.push_back(nums[i]);
                solve(i+1,nums,subsets,result);
                subsets.pop_back();
            }
        }


    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int>subsets;
        sort(nums.begin(),nums.end());
        solve(0, nums,subsets,result);
        return result;
        
    }
};
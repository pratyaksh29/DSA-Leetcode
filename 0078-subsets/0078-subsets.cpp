class Solution {
public:
    void solve(int index, vector<int>& nums,vector<int>& subsets,vector<vector<int>>& result){
        if(index==nums.size()){ //base case 
            result.push_back(subsets);
            return;
        }

        //pick 
        subsets.push_back(nums[index]);
        solve(index+1 , nums, subsets,result);

        //dont pick
        subsets.pop_back();
        solve(index + 1, nums, subsets,result);

    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int>subsets;
        
        solve(0, nums,subsets,result);
        return result;
        
    }
};


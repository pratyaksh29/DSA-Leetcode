class Solution {
public:
    
    void solve(int index, int target,vector<int>& candidates, vector<int>& ds, vector<vector<int>>& result){
        
        if(index == candidates.size()){
            if(target==0){
                result.push_back(ds);
            }
            return;
        }

        //pick
        if(candidates[index]<=target){
            ds.push_back(candidates[index]);
            solve(index,target-candidates[index],candidates,ds,result);
            ds.pop_back();
        }
        
        //dont pick
        solve(index+1,target,candidates,ds,result);
    }


    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>result;
        vector<int>ds;
        solve(0,target,candidates,ds,result);
        return result;
    
    }
};
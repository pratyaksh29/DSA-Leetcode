class Solution {
public:

    void solve(int index, vector<int>& candidates, int target, vector<vector<int>>&result,vector<int>&temp){
        if(index == candidates.size()){
            if(target==0){
                result.push_back(temp);
            }
            return;
        }
        //pick
        if(candidates[index]<=target){
            temp.push_back(candidates[index]);
            solve(index,candidates,target-candidates[index],result,temp);
            temp.pop_back();
        }

        solve(index+1,candidates,target,result,temp);

    }


    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>result;
        vector<int>temp;
        solve(0, candidates,target,result,temp);
        return result;

        
    }
};
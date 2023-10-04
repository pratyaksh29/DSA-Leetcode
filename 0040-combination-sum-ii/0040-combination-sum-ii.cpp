class Solution {
public:
    void solve(int index, int target,vector<int>& candidates,vector<int>& ds,vector<vector<int>>& result){
        if(target==0){
            result.push_back(ds);
            return;
        }

        

        for(int i =index;i<candidates.size();i++){
            if(i == index || candidates[i] != candidates[i-1]){

                if(candidates[i]<=target){
                    ds.push_back(candidates[i]);
                    solve(i+1,target - candidates[i],candidates,ds,result);
                    ds.pop_back();
                }
            }
        }

    }






    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> ds;
        sort(candidates.begin(),candidates.end());
        solve(0,target,candidates,ds,result);
        return result;
    }
};
class Solution {
public:
    void solve(int ind, vector<vector<int>>&result, vector<int>&temp,vector<int>& cand, int target){

        if(target == 0){
            result.push_back(temp);
            return;
        }

        for(int i = ind; i <cand.size();i++){
            if(i==ind || cand[i-1] != cand[i]){
                if(cand[i]<=target){
                    temp.push_back(cand[i]);
                    solve(i+1,result,temp,cand,target-cand[i]);
                    temp.pop_back();
                }

            }

        }

    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>>result;
        vector<int>temp;
        sort(candidates.begin(),candidates.end());
        solve(0,result,temp,candidates,target);
        return result;
    }
};
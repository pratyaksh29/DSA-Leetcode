class Solution {
public:

    void solve(vector<int>& temp,vector<vector<int>>&ans, vector<int>&nums,int freq[]){
        if(temp.size()==nums.size()){
            ans.push_back(temp);
            return;
        }

        for(int i=0;i<nums.size();i++){
            if(!freq[i]){
                temp.push_back(nums[i]);
                freq[i]=1;
                solve(temp,ans,nums,freq);
                temp.pop_back();
                freq[i]=0;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>temp;
        int n =nums.size();
        int freq[n];
        for(int i=0;i<n;i++){
            freq[i]=0;
        }
        solve(temp,ans,nums,freq);
        return ans;

    }
};
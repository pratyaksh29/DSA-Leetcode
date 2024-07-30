class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>>ans;
        for(auto it : intervals){
            if(ans.empty()|| it[0] > ans.back()[1]) { //start1>end0
                ans.push_back(it);
            }
            else{
                vector<int>previnterval = ans.back();
                ans.pop_back();
                ans.push_back({previnterval[0],max(it[1],previnterval[1])});
            }
        }
        return ans;
    }
};
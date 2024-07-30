class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);
        sort(intervals.begin(),intervals.end());
        vector<vector<int>>ans;
        for(auto it : intervals){
            if(ans.empty()||it[0]>ans.back()[1]){
                ans.push_back(it);
            }
            else{
                vector<int>prev = ans.back();
                ans.pop_back();
                ans.push_back({prev[0],max(prev[1],it[1])});
            }
        }
        return ans;
    }
};
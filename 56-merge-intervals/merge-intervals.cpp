class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n =intervals.size();
        sort(intervals.begin(),intervals.end());
        vector<vector<int>>ans;
        for(int i =0;i<n;i++){
            int start = intervals[i][0]; //starting of range
            int end = intervals[i][1];  //ending of range
            if(ans.empty() || start>ans.back()[1]){ 
                ans.push_back({start,end});
            }
            else{
                ans.back()[1] = max(ans.back()[1],end);
            }
        }
        return ans;
    }
};



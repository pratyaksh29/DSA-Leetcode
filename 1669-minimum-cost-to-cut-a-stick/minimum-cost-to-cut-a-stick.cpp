class Solution {
private:
    int f(int i, int j,vector<int>& cuts,vector<vector<int>>&dp){
        if(i>j){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int mini= 1e9;
        for(int ind =i;ind<=j;ind++){ //go till j
            int cost = cuts[j+1]-cuts[i-1] + f(i,ind-1,cuts,dp) + f(ind+1,j,cuts,dp); //compute the length with is cuts[j+1]-cuts[i-1]
                                                                                     //compute the left and right sides of the cuts
            if(cost<mini){
                mini=cost;
            }
        }
        return dp[i][j] = mini;
    }
public:
    int minCost(int n, vector<int>& cuts) {
        int c = cuts.size();

        cuts.push_back(n); //push the last element
        cuts.push_back(0); //push the first element and sort it
        sort(cuts.begin(),cuts.end());
        
        vector<vector<int>>dp(c+2,vector<int>(c+2,0)); //make the dp array with c because thats the total number of cuts

        
        for(int i=c;i>=1;i--){
            for (int j = 1; j <= c; j++) {
                if (i > j) continue;
                int mini = INT_MAX;
                for (int ind = i; ind <= j; ind++) {
                // Calculate the cost for making a cut at position 'ind'.
                    int ans = cuts[j + 1] - cuts[i - 1] + dp[i][ind - 1] + dp[ind + 1][j];
                    mini = min(mini, ans);
                }
                dp[i][j]=mini;
            }
        }
        return dp[1][c];
    }
};


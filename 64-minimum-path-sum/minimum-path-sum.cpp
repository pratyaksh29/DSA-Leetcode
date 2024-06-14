class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int>prev(m,INT_MAX);
        vector<int>curr(m,INT_MAX);

        prev[0]=grid[0][0];
        

        for(int i =0;i<n;i++){
            int up =INT_MAX;
            int left = INT_MAX;
            for(int j=0;j<m;j++){
                curr[j]= grid[i][j];
                if(i!=0 || j!=0){ 
                    if(j-1>=0){
                        up = curr[j-1];
                    }
                    if(i-1>=0){
                        left = prev[j];
                    }
                    curr[j] += min (up,left);
                }
            }
            prev = curr;
        }
        return prev[m-1];
    }
};

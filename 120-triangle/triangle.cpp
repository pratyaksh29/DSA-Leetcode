class Solution {
public:

    int minimumTotal(vector<vector<int>>& triangle) {
        int row = triangle.size();
        int col = triangle[0].size();
        vector<int>prev(row, 0);
        vector<int>curr(row, 0);

        for(int j=0;j<row;j++){
            prev[j]=triangle[row-1][j];
        }
        for(int i = row-2;i>=0;i--){
            for(int j=i;j>=0;j--){

                int down = triangle[i][j] +prev[j];
                int right = triangle[i][j] +prev[j+1];
                curr[j] = min(down, right); 

            }
            prev=curr;
        }
        return prev[0];
    }
};

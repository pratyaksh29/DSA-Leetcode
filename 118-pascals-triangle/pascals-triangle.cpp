class Solution {
    vector<int>gentemp(int row){
        vector<int>temp;
        long long num = 1;
        temp.push_back(num);
        for(int col =1 ;col<row;col++){ 
            num = num * (row-col);
            num = num / col;
            temp.push_back(num);
        }
        return temp;
    }
public:
    vector<vector<int>> generate(int numRows) {
        int n = numRows;
        vector<vector<int>>ans;

        for(int i=1;i<=n;i++){
            ans.push_back(gentemp(i));
        }
        return ans;
    }
};
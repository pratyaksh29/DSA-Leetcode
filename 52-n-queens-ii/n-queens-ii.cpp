class Solution {
public:

    bool issafe(int row,int col, vector<string>&board, int n){
        int duprow = row;
        int dupcol = col;
        while(row>=0 && col>=0){ //upper diagonal
            if(board[row][col]=='Q'){
                return false;
            }
            row--;
            col--;
        }
        row = duprow;
        col = dupcol;

        while(row<n && col>=0){ //lower diagonal
            if(board[row][col]=='Q'){
                return false;
            }
            col--;
            row++;
        }

        row = duprow;
        col = dupcol;

        while(col>=0){ //left
            if(board[row][col]=='Q'){
                return false;
            }
            col--;
        }
        return true;
    }
    set<vector<string>>st;

    void solve(int col,vector<string>&board,vector<vector<string>>&ans,int n){
        if(col==n){ //if it reaches the last column
            st.insert(board);
            if(st.find(board)!=st.end()){
                ans.push_back(board);
            }
            return;
        }
        for(int row = 0;row<n;row++){
         
            if(issafe(row,col,board,n)){
                board[row][col] = 'Q';
                solve(col+1,board,ans,n);
                board[row][col]= '.'; //backtrack
            }
        }
    }

    int totalNQueens(int n) {
        vector<vector<string>>ans;
        vector<string>board(n);
        string s(n,'.');
        for(int i =0;i<n;i++){
            board[i]=s; //if n = 4 -> board will have 4 rows of ....
        }
        solve(0,board,ans,n);
        return ans.size();
    }
};
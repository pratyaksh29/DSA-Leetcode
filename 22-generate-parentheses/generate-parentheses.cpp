class Solution {
public:
    void solve(vector<string>&ans,string &str,int n,int open, int close){ //open>close always
        if(n==open && n==close){
            ans.push_back(str);
            return;
        }
        //open or close

        if(open<n){
            str.push_back('(');
            solve(ans,str,n,open+1,close);
            str.pop_back();
        }
        if(close<n && close<open){
            str.push_back(')');
            solve(ans,str,n,open,close+1);
            str.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        string str;
        solve(ans,str,n,0,0);
        return ans;
    }
};
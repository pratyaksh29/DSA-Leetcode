class Solution {
private:
    bool f(string &s,string &p,int i,int j,vector<vector<int>>&dp){ //i -> string size ; //j -> pattern size
        if(i<0 && j<0){         //base case; if both are exhausted then this means that the pattern matched with the string
            return true;
        }
        if(i>=0 && j<0){        //if the pattern has exhausted but the string is still there 
            return false;      //then return false because there is no way that the string can match with the pattern
        }
        if(i<0 && j>=0){ //if the string has exhausted ; the pattern can still match with it if and only if it has all '*' in the string
            for(int k=0;k<=j;k++){
                if(p[k]!='*'){
                    return false;
                }
            }
            return true;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];        
        }
        if(s[i]==p[j]||p[j]=='?'){ //if it matches or the pattern has a ? ; we will just go back one place in both the string and pattern
            return dp[i][j] = f(s,p,i-1,j-1,dp);
        }
        if(p[j]=='*'){ //if it has a * then there can be 2 options -> one we stay at the current string and go to the next pattern (dont use the power of *)
            return dp[i][j] = f(s,p,i,j-1,dp) + f(s,p,i-1,j,dp);//-> other is that we stay at the current pattern (use power of *) and go to the next string letter
        }
        return false;  
    }
public:
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));

        return f(s,p,n-1,m-1,dp);
        
    }
};
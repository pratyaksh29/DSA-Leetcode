class Solution {
private:
    int f(int ind1, int ind2, string &text1, string &text2,vector<vector<int>> &dp){//pass by reference as everytime u call the string, it might give tle
        if(ind1<0 || ind2<0){
            return 0;
        }
        if(dp[ind1][ind2]!=-1){
            return dp[ind1][ind2];
        }
        if(text1[ind1]==text2[ind2]){
            return dp[ind1][ind2] = 1 + f(ind1-1, ind2-1, text1,text2,dp);
        }

        return dp[ind1][ind2] = max(f(ind1-1, ind2,text1,text2,dp),f(ind1, ind2-1,text1,text2,dp));
    } 
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        string t =s;
        reverse(t.begin(),t.end());
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return f(n-1,n-1,s,t,dp);

        
    }
};
class Solution {
private:
    int f(int i,int j , string &s, string &t,vector<vector<int>>&dp){

        if(j<0){ //if t is exhausted -> it means that we made all subsequences of s that could be made (cuz it only decrements when it matches ; thus we can return 1)
            return 1;
        }
        if(i<0){
            return 0; //if s is exhausted this wud mean that t still has letters left and thus we werent able to form subsequences in that recursive call
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(s[i]==t[j]){
            //pick the one thats matching + dont pick and go to the other letters to find if there are more matching
            return dp[i][j] = f(i-1,j-1,s,t,dp) + f(i-1,j,s,t,dp);
        }
        else{
            return dp[i][j]= f(i-1,j,s,t,dp);
        }
    }
public:
    int numDistinct(string s, string t) {
        
        int n = s.size();
        int m =t.size();
        vector<vector<double>>dp(n+1,vector<double>(m+1,0));
        for(int i =0;i<=n;i++){ //when j<0
            dp[i][0] = 1;
        }
        for(int j=1;j<=m;j++){ //got stuck here -> put j as 1 as you have already sorted j=0
            dp[0][j]=0;
        }
        for(int i =1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1]==t[j-1]){ //change here
                    dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
                }
                else{
                    dp[i][j]= dp[i-1][j];
                }

            }
        }
        return (int)dp[n][m];
    }
};

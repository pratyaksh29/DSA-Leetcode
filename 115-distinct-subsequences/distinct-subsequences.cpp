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
    int mod=1e9+7;
    int numDistinct(string s, string t) {
        int n = s.size();
        int m =t.size();
        vector<int>base(m+1,0);
        base[0]=1;
        for(int i =1;i<=n;i++){
            for(int j=m;j>=1;j--){ //very imp change to make it into 1D
                if(s[i-1]==t[j-1]){ 
                    base[j] = (base[j-1] + base[j]) %mod;
                }
            }
        }
        return base[m];
    }
};

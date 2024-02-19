class Solution {
// private:
//     int f(int i, int j, string s1, string s2,vector<vector<int>>&dp){
//         if(i<0){
//             return j+1; //if i is empty -> we need to add j+1 elements to make it equal
//         }
//         if(j<0){ //if j is empty, we need to delete i+1 elements to make it equal
//             return i+1;
//         }
//         if(dp[i][j]!=-1){
//             return dp[i][j];
//         }
//         if(s1[i]==s2[j]){ //if both letters equal, go to the prev letter on both strings
//             return dp[i][j]=0 + f(i-1,j-1,s1,s2,dp);
//         }
//         return dp[i][j]= 1 + min(f(i-1,j,s1,s2,dp),min(f(i,j-1,s1,s2,dp),f(i-1,j-1,s1,s2,dp)));
//          // min of delete,insert and replace
//     }
public:
    
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));

        for(int i=0;i<=n;i++){
            dp[i][0]= i; //imp -> one based indexing so we wont take j+1 and 
                        //take j instead because earlier when eg j=1,2 -> 
                        //we would return j+1 (cuz it would be 1(j)+1= 2 ) but now j = 2 instead of 1

        }
        for(int j =0;j<=m;j++){
            dp[0][j] =j;
        }

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(word1[i-1]==word2[j-1]){
                    dp[i][j]= dp[i-1][j-1];
                }
                else{
                    dp[i][j]= 1 + min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]));
                }

            }
        }
        return dp[n][m];
        
    }
};



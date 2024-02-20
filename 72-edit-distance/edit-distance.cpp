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
        vector<int>base(m+1,0);
        vector<int>curr(m+1,0);
        // on any i row -> first column is i

        for(int j =0;j<=m;j++){
            base[j] =j; //on any column ; first element is equal to index number
        }

        curr[0]=0;

        for(int i=1;i<=n;i++){
            curr[0]=i;
            for(int j=1;j<=m;j++){ //go from 1 to m
                if(word1[i-1]==word2[j-1]){ //check if the words are equal ; make sure u use i-1 and j-1
                    curr[j]= base[j-1];
                }
                else{
                    curr[j]= 1 + min(base[j],min(curr[j-1],base[j-1]));
                }

            }
            base = curr;
        }
        return base[m]; //output this instead of dp[n][m]
        
    }
};



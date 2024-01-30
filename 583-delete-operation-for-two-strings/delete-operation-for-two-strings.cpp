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
    int minDistance(string word1, string word2) {
        int m=word1.size();
        int n=word2.size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        int a = f(word1.size()-1,word2.size()-1,word1,word2,dp);
        int dels = (m-a) + (n-a);
        return dels;
    }
};
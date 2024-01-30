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
    int longestCommonSubsequence(string text1, string text2) { //tabulation -> shift all index to the right
        int a = text1.size();
        int b = text2.size();
        vector<int>prev(b+1,0),curr(b+1,0); 

        for(int i =0;i<=b;i++){
            prev[i]=0;
        }

        for(int i =1;i<=a;i++){
            for(int j=1;j<=b;j++){
                if(text1[i-1]==text2[j-1]){ 
                    curr[j] = 1 + prev[j-1];
                }
                else{
                    curr[j]=max(prev[j],curr[j-1]);
                }
            }
            prev = curr;
        }
        return prev[b]; //return [a][b] instead of [a-1][b-1] as we are shifting
        
    }
};


class Solution {
private:
    bool isPalindrome(int i,int j,string &s){ //check for palindrome
        while(i<=j){
            if(s[i]!=s[j]){
                return false;
            }
            else{
                i++;
                j--;
            }
        }
        return true;
    }

    int f(int i,int n,string &s,vector<int>&dp){
        if(i==n){ //if i crosses the size of the string then return 0
            return 0;
        }

        if(dp[i]!=-1){
            return dp[i];
        }

        int mini=1e9;

        for(int j=i;j<n;j++){ //check from j=i to the entire string
            if(isPalindrome(i,j,s)){ //check for palindrome  -> we can just use the index because then it will only check the string in that index range
                int cost = 1 + f(j+1,n,s,dp); //if palindrome -> add cost as 1 and then do a partition and check from the next index
                mini = min(cost,mini); //store minimum cost
            }
        }
        return dp[i] = mini;
    }

public:
    int minCut(string s) {
        int n = s.size();
        vector<int>dp(n+1,-1);
        return f(0,n,s,dp)-1; //do -1 in the end because they end up doing an extra partition in the end which doesnt have to be accounted for
    }
};





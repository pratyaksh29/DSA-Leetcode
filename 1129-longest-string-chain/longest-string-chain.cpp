class Solution {
private:
    bool compare(string &a, string &b){ //a bigger, b smaller
        if(a.size() != b.size() + 1){
            return false; // Length difference is more than 1
        }
        int first = 0;
        int second = 0;
        bool foundDifference = false;
        while(first < a.size() && second < b.size()){
            if(a[first] == b[second]){
                first++;
                second++;
            }
            else{
                if(foundDifference){
                    return false; // Already found one difference, can't have more than 1
                }
                foundDifference = true;
                first++;
            }
        }
        return true;
    }

    
public:
    static bool comp(string &a, string &b) {
        return a.size() < b.size();
    }

    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),comp);
        int n=words.size();
        int maxi =1;
        vector<int>dp(n,1); //for the length
        for(int i = 1;i<n;i++){
            for(int j=0;j<i;j++){

                if(compare(words[i],words[j])&& 1+dp[j]>dp[i]){
                    dp[i] = 1+dp[j];
                }
            }
            maxi = max(maxi , dp[i]);
        }
        
        return maxi;
    }
};
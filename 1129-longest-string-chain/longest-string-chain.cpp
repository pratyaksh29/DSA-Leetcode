class Solution {
    
private:
    bool compare(string &a, string &b){ //a bigger, b smaller
        if(a.size()<b.size()){
            swap(a,b);
        }
        if(a.size()!=b.size()+1){
            return false;
        }
        int first = 0;
        int second = 0;
        while(first<a.size()){ //doesnt exceed the bigger string
            if(a[first]==b[second] && second<b.size()){
                first++;
                second++;
            }
            else{
                first++;
            }
        }
        if(first==a.size()&&second==b.size()){
            return true;
        }
        return false;



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
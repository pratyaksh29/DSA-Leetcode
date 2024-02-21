class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        
        vector<int>base(m+1,0),curr(m+1,0);
        
        base[0] = 1;

        for(int j =1;j<=m;j++){
            bool flag = true;
            for(int k=1;k<=j;k++){
                if(p[k-1]!='*'){
                    flag = false;
                }
            }
            base[j] = flag;
            
        }

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1]==p[j-1] || p[j-1]=='?'){
                    curr[j]=base[j-1];
                }
                else if(p[j-1]=='*'){ 
                    curr[j] = base[j] || curr[j-1];
                }
                else{
                    curr[j] = 0;
                }
            }
            base = curr;
        }
        return base[m];
    }
};
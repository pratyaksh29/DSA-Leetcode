class Solution {
public:
    bool isSubsequence(string s, string t) {
        int j = 0;
        int m = s.size(); //j
        int n = t.size(); //i
        for(int i =0 ; i < n && j<m;i++){
            if(s[j]==t[i]){
                j++;
            }
        }
        return j==m;
    }
};
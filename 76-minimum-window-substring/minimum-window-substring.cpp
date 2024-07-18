class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int>mp;
        for(int i=0;i<t.size();i++){
            mp[t[i]]++;
        }
        int l=0;
        int r =0;
        int m = s.length();
        int n =t.length();
        int minlen = 1e9;
        int c=0;
        int startindex=-1;
        while(r<m){
            if(mp.find(s[r])!=mp.end()){
                if(mp[s[r]]>0){
                    c++;
                }
                mp[s[r]]--;
            }
            while(c==n){
                if(r-l+1<minlen){
                    minlen = r-l+1;
                    startindex=l;
                }
                if(mp.find(s[l]) != mp.end()){
                    mp[s[l]]++;
                    if(mp[s[l]]>0){
                        c--;
                    }
                }
                l++;
            }
            r++;
        }
        return startindex == -1? "" : s.substr(startindex,minlen);
    }
};
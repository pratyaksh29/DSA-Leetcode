class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        int c=0;
        int l=0;
        int r =0;
        unordered_map<char,int>mp;
        while(r<n){
            mp[s[r]]++;
            while(mp.size()==3){
                c+=n-r;
                mp[s[l]]--;
                if(mp[s[l]]==0){
                    mp.erase(s[l]);
                }
                l++;
            }
            r++;
        }
        return c;
    }
};
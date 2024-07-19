class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char,int>mp;
        unordered_map<char,int>mp2;
        for(int i =0;i<s1.size();i++){
            mp[s1[i]]++;
        }
        int r =0;
        int l=0;
        while(r<s2.size()){
            mp2[s2[r]]++;
            if(r-l+1>s1.size()){
                if(mp2.find(s2[l])!=mp2.end()){
                    mp2[s2[l]]--;
                }
                if (mp2[s2[l]] == 0) {
                    mp2.erase(s2[l]);
                }
                l++;
            }
            if(r-l+1==s1.size() && mp == mp2){
                return true;
            }
            r++;
        }
        return false;
    }
};
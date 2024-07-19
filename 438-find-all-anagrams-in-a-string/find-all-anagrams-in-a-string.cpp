class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int>ans;
        unordered_map<char,int>mp;
        unordered_map<char,int>mp2;
        for(int i =0;i<p.size();i++){
            mp[p[i]]++; 
        }
        int r =0;
        int l=0;
        while(r<s.size()){
            mp2[s[r]]++; //keep putting letters in the map
            if(r-l+1>p.size()){ 
//if size of window increases the size of p -> we will start shrinking from the left
                if(mp2.find(s[l])!=mp2.end()){
                    mp2[s[l]]--;
                }
                if (mp2[s[l]] == 0) {
                    mp2.erase(s[l]);
                }
                l++;
            }
            if(r-l+1==p.size() && mp == mp2){ //if both maps are equal and window size = p.size() return true
                ans.push_back(l);
            }
            r++;//move window to right
        } 
        return ans;;
    }
        
    
};
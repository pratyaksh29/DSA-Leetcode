class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int l =0;
        int r =0;
        unordered_set<char>st;
        int maxlen = 0;
        while(r<n){
            if(st.find(s[r])==st.end()){
                st.insert(s[r]);
                maxlen = max(maxlen , r-l+1);
                r++;
            }
            else{
                st.erase(s[l]);
                l++;
            }
        }
        return maxlen;
    }
};
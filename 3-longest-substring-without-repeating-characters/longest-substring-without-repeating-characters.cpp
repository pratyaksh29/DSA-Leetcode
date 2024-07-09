class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        unordered_set<char> st; 
        int maxi = 0; 
        int l = 0, r = 0;
        
        while (r < n) {
            if (st.find(s[r]) == st.end()) {
                st.insert(s[r]);
                r++;
                maxi = max(maxi, r - l);
            } else {
                st.erase(s[l]);
                l++;
            }
        }
        
        return maxi;
    }
};

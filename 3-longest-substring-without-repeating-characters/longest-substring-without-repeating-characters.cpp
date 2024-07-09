class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int maxi = 0;
        
        for (int i = 0; i < n; i++) {
            unordered_set<char> st;
            for (int j = i; j < n; j++) {
                if (st.find(s[j]) != st.end()) {
                    break; 
                }
                st.insert(s[j]);
                maxi = max(maxi, j - i + 1); 
            }
        }
        return maxi;
    }
};

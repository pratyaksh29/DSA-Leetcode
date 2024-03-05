class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n==0||n==1){
            return n;
        }
        unordered_set<int>st;
        int longest = 1;
        for(auto i : nums){
            st.insert(i);
        }
        for(auto it : st){
            int prev =it-1;
            if(st.find(prev)!=st.end()){ //prev exists
                continue;
            }
            else{
                int c = 1;
                int x = it;
                while(st.find(x+1)!=st.end()){
                    c++;
                    x++;
                }
                longest = max(longest,c);
            }
        }
        
        return longest;
    }
};
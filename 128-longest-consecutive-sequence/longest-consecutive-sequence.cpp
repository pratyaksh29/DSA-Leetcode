class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n==0){
            return 0;
        }
        int longest =1;
        unordered_set<int>st;
        for(auto it : nums){
            st.insert(it);
        }

        for(auto it : nums){
            int prev = it-1;
            if(st.find(prev)!=st.end()){
                continue;
            }
            else{
                int c=1;
                int x = it;
                while(st.find(x+1)!=st.end()){
                    x++;
                    c++;
                }
                longest = max(longest,c);
            }

        }
        return longest;


    }
};
class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        vector<int>ans;
        stack<int>st;
        int n = prices.size();
        for(int i = n-1;i>=0;i--){ //st top <prices i
            while(!st.empty() && st.top()>prices[i]){
                st.pop();
            }
            if(st.empty()){
                ans.push_back(prices[i]);
            }
            else{ //prices[i] > st.top()
                ans.push_back(prices[i]-st.top());
            }
            st.push(prices[i]);
        }
        reverse(ans.begin(),ans.end());
        return ans;
       
    }
};
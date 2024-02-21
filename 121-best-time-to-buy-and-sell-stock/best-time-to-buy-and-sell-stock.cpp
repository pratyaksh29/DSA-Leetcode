class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini = prices[0];
        int maxprofit = 0;
        for(auto num:prices){
            int cost = num - mini;
            maxprofit = max(maxprofit,cost);
            mini = min(mini,num);
        }
        return maxprofit;
        
    }
};
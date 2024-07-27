class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l = 0;
        int r =1;
        int maxi = INT_MIN;
        while(r<prices.size()){
            if(prices[r]>=prices[l]){
                int profit = prices[r]-prices[l];
                maxi = max(maxi,profit);
            }
            else{
                l=r;
            }
            r++;
        }
        if(maxi < 0){
            return 0;
        }
        return maxi;
    }
};
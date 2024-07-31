class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l =0;
        int r =1;
        int maxi = 0;
        while(r<prices.size()){
            if(prices[r]>prices[l]){
                maxi = max(maxi,prices[r]-prices[l]);
            }
            else{
                l=r;
            }
            r++;
        }

        return maxi;
    }
};
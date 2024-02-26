class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n,1),hash(n); //dp stores length, hash stores index
        int maxi = 1; //max length found so far
        int last = 0; //index of last index
        sort(nums.begin(),nums.end());

        for(int i =0;i<n;i++){
            hash[i]=i;
            for(int prev =0;prev<i;prev++){
                if(nums[i]%nums[prev]==0 && 1 + dp[prev]>dp[i]){//second condition is for length
                    dp[i]=1+dp[prev];
                    hash[i] = prev;
                } 

            }
            if(dp[i]>maxi){
                maxi = max(maxi,dp[i]); 
                last = i;
            }
        }

        vector<int>temp;
        temp.push_back(nums[last]); //insert the first element that is for sure going to be in the subset

        while(hash[last]!=last){ //trace back
            last = hash[last];
            temp.push_back(nums[last]);
        }

        reverse(temp.begin(),temp.end());

        return temp;

        
    }
};


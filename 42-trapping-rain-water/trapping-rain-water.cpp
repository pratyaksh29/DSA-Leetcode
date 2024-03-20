class Solution {
public:
    vector<int> left(vector<int>& height){ //max 
        int n = height.size();
        vector<int>res(n);

        int maxi = height[0]; //stuck here
        res[0] = height[0]; //make sure u initialise this first
    
        for(int i =1;i<n;i++){
            maxi = max(maxi,height[i]);
            res[i] =maxi;
        }   
        return res;
    }
    vector<int> right(vector<int>& height){
        int n = height.size();
        vector<int>res(n);

        res[n-1] = height[n-1];
        int maxi = height[n-1]; //stuck here

        for(int i =n-2;i>=0;i--){
            maxi = max(maxi,height[i]);
            res[i] =maxi;
        } 
        return res; 
    }

    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> leftlimit = left(height);
        vector<int> rightlimit = right(height);
        int ans = 0;

        for (int i = 0; i < n; i++) {
            int limit = min(leftlimit[i], rightlimit[i]);
            ans += max(0, limit - height[i]);
        }

        return ans;
    }
};
class Solution {
private:
    int f(int n, int m, vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& dp, int& ans) {
        if (n < 0 || m < 0) {
            return 0;
        }
        if (dp[n][m] != -1) {
            return dp[n][m];
        }
        int take = 0;
        if (nums1[n] == nums2[m]) {
            take = 1 + f(n - 1, m - 1, nums1, nums2, dp, ans);
        }
 
        f(n - 1, m, nums1, nums2, dp, ans);
        f(n, m - 1, nums1, nums2, dp, ans);

        ans = max(ans, take);
        return dp[n][m] = take;
    }

public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        if (nums1 == nums2) {
            return nums1.size();
        }
        int a = nums1.size();
        int b = nums2.size();
        vector<vector<int>> dp(a + 1, vector<int>(b + 1, -1));
        int ans = 0; 
        f(a - 1, b - 1, nums1, nums2, dp, ans);
        return ans;
    }
};

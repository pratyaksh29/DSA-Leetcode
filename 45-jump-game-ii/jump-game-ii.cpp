class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.size() == 1) {
            return 0;
        }
        int n = nums.size() - 1;
        int ans = 0;
        int currentEnd = 0;
        int farthest = 0;
        
        for (int i = 0; i < n; ++i) {
            farthest = max(farthest, i + nums[i]);
            
            if (i == currentEnd) {
                ans++;
                currentEnd = farthest;
                
                if (currentEnd >= n) {
                    break;
                }
            }
        }
        
        return ans;
    }
};

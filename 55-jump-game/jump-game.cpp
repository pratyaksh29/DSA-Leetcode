class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int reach = 0; // Initialize reach to 0

        for (int i = 0; i <= reach; i++) {
            reach = max(reach, i + nums[i]); // Update reach to the maximum reachable index
            if (reach >= n - 1) {
                return true; // If the last index is reachable, return true
            }
        }

        return false;
    }
};

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        set<vector<int>> st;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                set<long long> hashset; // keep it here, not inside the loop
                for (int k = j + 1; k < n; k++) {
                    long long sum = nums[i] + nums[j];
                    sum+= nums[k]; //do this separately -> otherwise overflow
                    long long fourth = target - sum;
                    if (hashset.find(fourth) != hashset.end()) {
                        vector<int> temp = {nums[i], nums[j], nums[k], (int)fourth};
                        sort(temp.begin(), temp.end());
                        st.insert(temp);
                    }
                    hashset.insert(nums[k]);

                }
            }
        }
        vector<vector<int>> ans(st.begin(), st.end());
        return ans;
    }
};

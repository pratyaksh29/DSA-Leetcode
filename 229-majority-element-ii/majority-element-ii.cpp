class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        vector<int> result;
        unordered_map<int, int> counts;//num and frequency
        
        // Count the occurrences of each element
        for (int num : nums) {
            counts[num]++;
        }
        
        // Find the elements that appear more than n/3 times
        for (auto it : counts) {
            if (it.second > n / 3) {
                result.push_back(it.first);
            }
        }
        
        return result;
    }
};

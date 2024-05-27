class Solution {
public:
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        long long n = nums1.size();
        long long m = nums2.size();
        long long c = 0;
        
        unordered_map<int, int> mp;
        
        for (int j = 0; j < m; j++) {
            mp[nums2[j] * k]++;
        }
        
        for (int i = 0; i < n; i++) {
            if(nums1[i]%k!=0){
                continue;
            }
            for (int f=1;f*f<=nums1[i];f++) {
                if(nums1[i]%f!=0){
                    continue;
                }
                int f1 =f;
                int f2 = nums1[i]/f;
                c+= mp[f1];
                if(f1!=f2){
                    c+=mp[f2];
                }
            }
        }
        
        return c;
    }
};

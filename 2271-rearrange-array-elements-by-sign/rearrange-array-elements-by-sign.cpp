class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int  n = nums.size();   
        vector<int>temp1;
        vector<int>temp2;
        for(int i =0;i<n;i++){
            if(nums[i]>=0){
                temp1.push_back(nums[i]);
            }
            else{
                temp2.push_back(nums[i]);
            }
        }
        vector<int>res;
        for(int i =0;i<n/2;i++){
            res.push_back(temp1[i]);
            res.push_back(temp2[i]);
        }
        return res;

    }
};
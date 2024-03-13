class Solution {
public:
    int greater(vector<int>&arr,int num){
        int i;
        for( i =0;i<arr.size();i++){
            if(num==arr[i]){
                break;
            }
        }
        for(int j = i+1;j<arr.size();j++){
            if(arr[j]>num){
                return arr[j];
            }
        }
        return -1;
    }
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ans;
        for(int i =0;i<nums1.size();i++){
            ans.push_back(greater(nums2,nums1[i]));
        }
        return ans;
    }
};
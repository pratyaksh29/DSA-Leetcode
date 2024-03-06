
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int ct1=0;
        int ct2=0;
        int el1 =INT_MIN;
        int el2 = INT_MIN;
        
        for(int i =0;i<n;i++){
            if(ct1==0 && el2!=nums[i]){
                el1=nums[i];
                ct1=1;
            }
            else if(ct2==0 && el1!=nums[i]){
                el2=nums[i];
                ct2=1;
            }
            else if (nums[i]==el1){
                ct1++;
            }
            else if (nums[i]==el2){
                ct2++;
            }
            else{
                ct1--;
                ct2--;
            }
        }
        vector<int>ls;
        ct1=0;
        ct2=0;
        for(int i =0;i<n;i++){
            if(nums[i]==el1){
                ct1++;
            }
            if(nums[i]==el2){
                ct2++;
            }
        }
        if(ct1>n/3){
            ls.push_back(el1);
        }
        if(ct2>n/3){
            ls.push_back(el2);
        }
        return ls;


    }
};
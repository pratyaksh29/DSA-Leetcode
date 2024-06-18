class Solution {
public:
    void sortColors(vector<int>& nums) {
        int cnt0 = 0, cnt1 = 0, cnt2 = 0; 
        int n = nums.size();
        for(int i =0;i<n;i++){
            if(nums[i]==0){
                cnt0++;
            }
            else if(nums[i]==1){
                cnt1++;
            }
            else if(nums[i]==2){
                cnt2++;
            }
        }
        int i =0;
        while(cnt0--){
            nums[i]=0;
            i++;
        }
        while(cnt1--){
            nums[i]=1;
            i++;
        }
        while(cnt2--){
            nums[i]=2;
            i++;
        }
        
        
    }

};
class Solution {
public:
    void merge(vector<int>&nums, int low, int mid, int high){
        int i = low;
        int j = mid+1;
        vector<int>temp;
        while(i<=mid && j <= high){
            if(nums[i]<=nums[j]){
                temp.push_back(nums[i]);
                i++;
            }
            else{
                temp.push_back(nums[j]);
                j++;
            } 
        }
        while(i<=mid){
            temp.push_back(nums[i]);
            i++;
        }
        while(j<=high){
            temp.push_back(nums[j]);
            j++;
        }

        for(int k =0;k<temp.size();k++){
            nums[k + low] = temp[k];
        }
    }

    int countPairs(vector<int> &nums, int low, int mid, int high){
        int c= 0;
        int j=mid+1;
        for(int i =low;i<=mid;i++){
            while(j<=high && nums[i]> 2LL * nums[j]){
                j++;
            }
            c+=(j-(mid+1)); //we dont do another +1 because j gets incremented in the end ; 
        }                   //so it points to the number that is not to be added in the count
        return c;
    }

    int mergesort(vector<int>&nums,int low,int high){
        int c =0;
        if(low>=high){
            return c;
        }
        int mid = (high+low)/2;
        c+=mergesort(nums,low,mid);
        c+=mergesort(nums,mid+1,high);
        c+=countPairs(nums,low,mid,high);
        merge(nums,low,mid,high);
        return c;

    }




    int reversePairs(vector<int>& nums) {
        return mergesort(nums,0,nums.size()-1);
    }
};
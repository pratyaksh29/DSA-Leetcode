class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

        int k = m+n-1; //last index of nums 1 as it has m+n indexes
        int i = m-1; //last element of nums1
        int j = n-1; //last element of nums1

        //merge in reverse order

        while(j>=0){// got stuck -> basically run loop till j is 0 so u can insert every element from nums2 to nums1
            if(i>=0 && nums1[i]>nums2[j]){ //if i is greater than or equal to 0 then only u can insert elements
                nums1[k]=nums1[i];
                i--; //decrement and then check the prev element in nums1
            }
            else{
                nums1[k]=nums2[j];
                j--; //decrement and then check the prev element in nums2
            }
            k--; //decrement the index in nums1
        }


    }
};


class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            // If the middle element is less than the high element, the minimum is in the left half
            if (nums[mid] < nums[high]) {
                high = mid; // Search in the left half, including mid
            } 
            // If the middle element is greater than the high element, the minimum is in the right half
            else if (nums[mid] > nums[high]) {
                low = mid + 1; // Search in the right half, excluding mid
            } 
            // If the middle element is equal to the high element, we can't decide the minimum part, so reduce the search range by one
            else {
                high--;
            }
        }

        return nums[low];
    }
};

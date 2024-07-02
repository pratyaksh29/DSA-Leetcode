class Solution {
public:
    int findKthLargest(std::vector<int>& nums, int k) {
        return quickSelect(nums, 0, nums.size() - 1, nums.size() - k);
    }

private:
    int quickSelect(std::vector<int>& nums, int left, int right, int k) {
        if (left == right) {
            return nums[left];
        }

        int pivotIndex = left + rand() % (right - left + 1);
        pivotIndex = partition(nums, left, right, pivotIndex);

        if (k == pivotIndex) {
            return nums[k];
        } else if (k < pivotIndex) {
            return quickSelect(nums, left, pivotIndex - 1, k);
        } else {
            return quickSelect(nums, pivotIndex + 1, right, k);
        }
    }

    int partition(std::vector<int>& nums, int left, int right, int pivotIndex) {
        int pivotValue = nums[pivotIndex];
        std::swap(nums[pivotIndex], nums[right]);  // Move pivot to end
        int storeIndex = left;

        for (int i = left; i < right; ++i) {
            if (nums[i] < pivotValue) {
                std::swap(nums[storeIndex], nums[i]);
                storeIndex++;
            }
        }

        std::swap(nums[right], nums[storeIndex]);  // Move pivot to its final place
        return storeIndex;
    }
};

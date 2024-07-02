class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>>minheap(nums.begin(),nums.begin()+k);

        for(int i =k;i<nums.size();i++){
            if(nums[i]>minheap.top()){
                minheap.pop();
                minheap.push(nums[i]);
            }
        }
        return minheap.top();
    }
};
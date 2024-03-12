class Solution {

void merge(vector<int> &arr, int low, int mid, int high) { //no changes
    vector<int> temp; // temporary array
    int left = low;      // starting index of left half of arr
    int right = mid + 1;   // starting index of right half of arr


    //storing elements in the temporary array in a sorted manner//

    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            temp.push_back(arr[left]);
            left++;
        }
        else {
            temp.push_back(arr[right]);
            right++;
        }
    }

    // if elements on the left half are still left //

    while (left <= mid) {
        temp.push_back(arr[left]);
        left++;
    }

    //  if elements on the right half are still left //
    while (right <= high) {
        temp.push_back(arr[right]);
        right++;
    }

    // transfering all elements from temporary to arr //
    for (int i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }

}

int countPairs(vector<int> &arr, int low, int mid, int high){
    int c= 0;
    int j=mid+1;
    for(int i =low;i<=mid;i++){
        while(j<=high && arr[i]> 2LL * arr[j]){
            j++;
        }
        c+=(j-(mid+1)); //we dont do another +1 because j gets incremented in the end ; 
    }                   //so it points to the number that is not to be added in the count
    return c;
}


int mergeSort(vector<int> &arr, int low, int high) {
    int c =0;
    if (low >= high) return c;
    int mid = (low + high) / 2 ;
    c += mergeSort(arr, low, mid);  // left half
    c+= mergeSort(arr, mid + 1, high); // right half
    c+= countPairs(arr,low,mid,high); //add the count pair function here and add all to the total count
    merge(arr, low, mid, high);  // merging sorted halves
    return c;
}



public:
    int reversePairs(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size() - 1);
    }
};



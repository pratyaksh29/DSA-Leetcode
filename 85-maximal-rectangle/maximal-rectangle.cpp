class Solution {
public:
    vector<int> nsr(vector<int>& heights) {
        vector<int> ans;
        int n = heights.size();
        stack<pair<int, int>> st; // height, index
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && st.top().first >= heights[i]) {
                st.pop();
            }
            if (!st.empty() && st.top().first < heights[i]) {
                ans.push_back(st.top().second); //push the nearest smallest height's index
            } else {
                ans.push_back(n); // Assume a virtual bar of height 0 at the end ; stuck here
            }
            st.push({heights[i], i});
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }

    vector<int> nsl(vector<int>& heights) {
        vector<int> ans;
        int n = heights.size();
        stack<pair<int, int>> st; // height, index
        for (int i = 0; i < n; i++) {
            while (!st.empty() && st.top().first >= heights[i]) {
                st.pop();
            }
            if (st.empty()) {
                ans.push_back(-1); // the index on left of 0 
            } else {
                ans.push_back(st.top().second); //push the nearest smallest height's index
            }
            st.push({heights[i], i});
        }
        return ans;
    }

    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int maxi = INT_MIN;
        vector<int> nsr_indices = nsr(heights); //call the vector here not in the function
        vector<int> nsl_indices = nsl(heights);
        for (int i = 0; i < n; i++) {
            int ind = nsr_indices[i] - nsl_indices[i] - 1; //stuck here
            maxi = max(maxi, heights[i] * ind); //calculating area
        }
        return maxi;
    }
    //all the code above is from-> https://leetcode.com/problems/largest-rectangle-in-histogram/

    int maximalRectangle(vector<vector<char>>& matrix) {
        int r = matrix.size();
        if (r == 0) return 0; //base case
        int c = matrix[0].size();
        int maxi = INT_MIN;
        vector<int>height(c);
        for(int j =0;j<c;j++){ //first row
            height[j] = matrix[0][j]- '0';
            maxi = max(maxi ,largestRectangleArea(height));
        }
        for(int i =1;i<r;i++){
            for(int j=0;j<c;j++){
                if(matrix[i][j] == '0'){
                    height[j] = 0;
                }
                else{
                    height[j] += (matrix[i][j]- '0');
                }
            }
            maxi = max(maxi ,largestRectangleArea(height));
        }
        return maxi;
    }
};

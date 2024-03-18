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
                ans.push_back(st.top().second); // Corrected calculation
            } else {
                ans.push_back(n); // Assume a virtual bar of height 0 at the end
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
                ans.push_back(-1); // Corrected condition
            } else {
                ans.push_back(st.top().second);
            }
            st.push({heights[i], i});
        }
        return ans;
    }

    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int maxi = INT_MIN;
        vector<int> nsr_indices = nsr(heights); //call here not in the function
        vector<int> nsl_indices = nsl(heights);
        for (int i = 0; i < n; i++) {
            int ind = nsr_indices[i] - nsl_indices[i] - 1; //stuck here
            maxi = max(maxi, heights[i] * ind);
        }
        return maxi;
    }
};

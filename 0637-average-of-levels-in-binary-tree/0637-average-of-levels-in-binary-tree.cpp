/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> sum;   // Vector to store the sum of values for each level.
        vector<int> count;    // Vector to store the count of nodes for each level.
        vector<double> averages; // Vector to store the calculated average values.

        // Start DFS traversal from the root node at level 0.
        dfs(root, 0, sum, count);

        // Calculate the averages for each level.
        for (int i = 0; i < sum.size(); i++) {
            averages.push_back(sum[i] / count[i]); // Calculate average as sum/count.
        }

        return averages; // Return the vector of average values.
    }

    void dfs(TreeNode* node, int level, vector<double>& sum, vector<int>& count) {
        if (!node) {
            return; // Base case: If the current node is null, return.
        }

        // Check if the current level is greater than or equal to the size of sum and count vectors.
        if (level >= sum.size()) {
            sum.push_back(0);   // Initialize sum for the new level as 0.
            count.push_back(0); // Initialize count for the new level as 0.
        }

        sum[level] += node->val; // Add the value of the current node to the sum of the current level.
        count[level]++; // Increment the count of nodes at the current level.

        // Recursively call dfs for left and right children with an incremented level.
        dfs(node->left, level + 1, sum, count);
        dfs(node->right, level + 1, sum, count);
    }
};

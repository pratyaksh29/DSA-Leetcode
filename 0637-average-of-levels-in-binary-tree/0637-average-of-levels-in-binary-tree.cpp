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
        vector<double> sum;
        vector<int> count;
        vector<double> averages;

        dfs(root, 0, sum, count);

        for (int i = 0; i < sum.size(); i++) {
            averages.push_back(sum[i] / count[i]);
        }

        return averages;
    }

    void dfs(TreeNode* node, int level, vector<double>& sum, vector<int>& count) {
        if (!node) {
            return;
        }

        if (level >= sum.size()) {
            sum.push_back(0);
            count.push_back(0);
        }

        sum[level] += node->val;
        count[level]++;

        dfs(node->left, level + 1, sum, count);
        dfs(node->right, level + 1, sum, count);
    }
};

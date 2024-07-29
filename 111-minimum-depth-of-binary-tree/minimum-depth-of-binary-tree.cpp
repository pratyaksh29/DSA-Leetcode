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

    int minDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        
        // If one of the children is NULL, we should only consider the depth of the non-NULL child
        if (root->left == nullptr) {
            return minDepth(root->right) + 1;
        }
        if (root->right == nullptr) {
            return minDepth(root->left) + 1;
        }
        
        // If both children are non-NULL, we take the minimum of the depths
        int lh = minDepth(root->left);
        int rh = minDepth(root->right);
        return min(lh, rh) + 1;
    }
};

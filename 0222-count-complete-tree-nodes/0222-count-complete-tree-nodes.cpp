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
    int countNodes(TreeNode* root) {
        int count = 0;
        inorderCount(root, count);
        return count;
    }

    void inorderCount(TreeNode* node, int& count) {
        if (node == nullptr) {
            return;
        }

        // Traverse left subtree
        inorderCount(node->left, count);

        // Visit current node (increment count)
        count++;

        // Traverse right subtree
        inorderCount(node->right, count);
    }
};

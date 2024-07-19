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
    bool bst(TreeNode* root, long long mini, long long maxi){
        if(root==NULL){
            return true;
        }
        if(root->val <=mini || root->val >= maxi){
            return false;
        }
        return bst(root->left,mini,root->val) && bst(root->right,root->val,maxi);

    }
    bool isValidBST(TreeNode* root) {
        if(root==NULL){
            return true;
        }
        return bst(root,(long long)LONG_MIN,(long long)LONG_MAX );
        
    }
};
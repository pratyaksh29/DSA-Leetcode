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
    TreeNode* findrightmost(TreeNode* node){
        while(node->right!= NULL){

            node = node->right;
        }
        return node;
    }
    TreeNode* connectLogic(TreeNode* root) {
        // if there is only one child
        if (root->left == NULL) {
            return root->right;
        }
        if (root->right == NULL) {
            return root->left;
        }
        // if there are 2 children
        TreeNode* rightChild = root->right;
        TreeNode* rightmost = findrightmost(root->left);
        rightmost->right = rightChild;
        return root->left;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL){
            return NULL;
        }
        if(root->val == key){
            return connectLogic(root);
        }
        TreeNode* dummy = root;
        while(root!=NULL){
            if(root->val>key){
                if(root->left && root->left->val == key){
                    root->left = connectLogic(root->left); //make sure u connect root->left
                }
                else{
                    root = root->left;
                }
            }
            else{
                if(root->right && root->right->val == key){
                    root->right  = connectLogic(root->right);
                }
                else{
                    root = root ->right;
                }
            }
        }
        return dummy;
    }
};
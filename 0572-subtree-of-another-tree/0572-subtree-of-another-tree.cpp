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
    bool sametree(TreeNode* root, TreeNode* subRoot){
        if(root == NULL || subRoot==NULL){
            return (root==subRoot);
        }
        return root->val == subRoot->val && sametree(root->left,subRoot->left) && sametree(root->right,subRoot->right);
    }


    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root == NULL || subRoot==NULL){
            return (root==subRoot);
        }

        if(!sametree(root,subRoot)){
            return isSubtree(root->left,subRoot) || isSubtree(root->right,subRoot);
        }
        return true;


        
    }
};
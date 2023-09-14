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
    int length(TreeNode* root){
        if(root==NULL)
        {
            return NULL;
        } //to find the length
        int left = length(root->left); //length of left subtree
        int right = length(root->right); //length of right subtree
        return max(left,right)+1; //for returning the length 
    }

    bool isBalanced(TreeNode* root) {
      if(root==NULL){
        return true;
      }
      int lefth = length(root->left);
      int righth= length(root->right);

      if(abs(lefth-righth)>1){
        return false;
      }
      bool left = isBalanced(root->left);
      bool right = isBalanced(root->right);

      if(!left || !right){
        return false;
      }
      else{
        return true;
      }

      
    }
};